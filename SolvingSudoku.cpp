#include "SolvingSudoku.h"
#include "DefiningBeginning.h"
#include<iostream>
using namespace std;

bool sign = false;
SUDOKU DoSudoku;

bool CheckingForDFS(int n, int key)
{
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (DoSudoku.map[j][i] == key)return false;
	}

	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (DoSudoku.map[i][j] == key)return false;
	}

	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (DoSudoku.map[i][j] == key)return false;
		}
	}

	return true;
}

int SolvingByDFS(int n)
{
	if (n > 80)
	{
		sign = true;
		return 0;
	}
	if (DoSudoku.map[n / 9][n % 9] != 0)
	{
		SolvingByDFS(n + 1);
	}
	else {
		for (int i = 1; i <= 9; i++)
		{
			if (CheckingForDFS(n, i) == true)
			{
				DoSudoku.map[n / 9][n % 9] = i;
				SolvingByDFS(n + 1);
				if (sign == true)return 0;
				DoSudoku.map[n / 9][n % 9] = 0;
			}
		}
	}
}


bool SolvingSudoku(FILE* rfp)
{
	FILE *wfp;
	errno_t err;
	err = fopen_s(&wfp,"sudoku.txt", "w");
	if (err!=0)
	{
		return false;
	}

	char blank;
	do {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fscanf_s(rfp, "%d%c", &DoSudoku.map[i][j], &blank);
			}
		}
		SolvingByDFS(0);
		sign = false;
		WritePutsToFile(wfp, DoSudoku);

	} while (fscanf_s(rfp, "%c", &blank) != EOF);

	fclose(wfp);
	return true;
}
