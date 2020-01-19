#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
#include"DefiningBeginning.h"
#include"GeneratingSudoku.h"
#include"SolvingSudoku.h"
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )	//隐藏运行的控制台窗口


int main(int argc, char* argv[])
{
	DefineBeginning command;
	//if generating sudoku
	if (strcmp(argv[1], "-c") == 0)
	{
		int n = command.ChageStringToNumber(argv[2]);
		//printf("%d\n\n", n);
		if (n == -1 || n == 0)
		{
			printf("Wrong:input wrong.\n");
		}
		else if (n == -2)
		{
			printf("Wrong:input too big.\n");
		}
		else {
			GenerateSudoku RequestN;
			if (RequestN.GeneratingSudoku(n))
				printf("Completed Generating!\n");
			else
				printf("Wrong:sudoku.txt doesn't exist.\n");
		}
	}//if solve sudoku
	else if (strcmp(argv[1], "-s") == 0) {
		FILE* fp;
		errno_t err;
		err = fopen_s(&fp, argv[2], "r");
		if (err != 0)
		{
			printf("Wrong:File open failed.\n");
		}
		else {
			SolveSudoku ProblemSudoku;
			if (ProblemSudoku.SolvingSudoku(fp))
			{
				printf("Successfully solved!\n");
			}
			else {
				printf("Wrong:sudoku.txt doesn't exist.\n");
			}
		}
		if (fp != 0)fclose(fp);
	}//if not 2 commands
	else
	{
		printf("Wrong:input wrong.\n");
	}
	return 0;
}