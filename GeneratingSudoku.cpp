#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
#include "GeneratingSudoku.h"
#include "DefiningBeginning.h"

int MovingStepDic[72][9] = { 0 };

//inline function to generating movingstepdictionary
inline void MovingStep()
{
	int MovingDic1[2][3] = { { 0,3,6 },{ 0,6,3 } };
	int MovingDic2[6][3] = { { 1,4,7 },{ 1,7,4 },{ 4,1,7 },{ 4,7,1 },{ 7,4,1 },{ 7,1,4 } };
	int MovingDic3[6][3] = { { 2,5,8 },{ 2,8,5 },{ 5,2,8 },{ 5,8,2 },{ 8,2,5 },{ 8,5,2 } };
	int step[10];
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				memcpy(&step[0], &MovingDic1[k][0], 3 * sizeof(int));
				memcpy(&step[3], &MovingDic2[j][0], 3 * sizeof(int));
				memcpy(&step[6], &MovingDic3[i][0], 3 * sizeof(int));
				memcpy(&MovingStepDic[count], &step[0], 9 * sizeof(int));
				count++;
			}
		}
	}
}

//bool function: generating sudoku false or success 
bool GeneratingSudoku(int n)
{
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp, "sudoku.txt", "w");
	if (err != 0) {
		return false;
	}
	MovingStep();
	int RequestFirstline[9] = { 8,9,1,2,3,4,5,6,7 };
	int JointLine[18];
	int num = 0;
	SUDOKU ResultingSudoku;
	memset(ResultingSudoku.map, 0, sizeof(ResultingSudoku.map));
	while (next_permutation(&RequestFirstline[1], &RequestFirstline[9]))
	{
		if (num >= n)break;
		for (int i = 0; i < 72; i++)
		{
			if (num >= n)break;
			memcpy(JointLine, RequestFirstline, sizeof(RequestFirstline));
			memcpy(&JointLine[9], RequestFirstline, sizeof(RequestFirstline));
			int j = num % 72;
			for (int k = 0; k < 9; k++)
			{
				int l = MovingStepDic[j][k];
				memcpy(&ResultingSudoku.map[k], &JointLine[l], 9 * sizeof(int));
			}
			WritePutsToFile(fp, ResultingSudoku);
			num++;
		}
	}
	fclose(fp);
	return true;
}

//void GeneratingProblem(int n);