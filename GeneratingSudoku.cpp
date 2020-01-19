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
				memcpy_s(&step[0], 3 * sizeof(int), &MovingDic1[k][0], 3 * sizeof(int));
				memcpy_s(&step[3], 3 * sizeof(int), &MovingDic2[j][0], 3 * sizeof(int));
				memcpy_s(&step[6], 3 * sizeof(int), &MovingDic3[i][0], 3 * sizeof(int));
				memcpy_s(&MovingStepDic[count], 9 * sizeof(int), &step[0], 9 * sizeof(int));
				count++;
			}
		}
	}
}

//bool function: generating sudoku false or success 
bool GenerateSudoku::GeneratingSudoku(int n)
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
			DefineBeginning command;
			command.WritePutsToFile(fp, ResultingSudoku);
			num++;
		}
	}
	if(fp!=0)fclose(fp);
	return true;
}

//void GeneratingProblem(int n);