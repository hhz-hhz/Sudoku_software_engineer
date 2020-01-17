#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DefiningBeginning.h"
#include"GeneratingSudoku.h"
#include"SolvingSudoku.h"

int main(int argc, char* argv[])
{
	if (strcmp(argv[1], "-c") == 0)
	{
		int n = ChageStringToNumber(argv[2]);
		//printf("%d\n\n", n);
		if (n == -1 || n == 0)
			printf("Wrong:input wrong.\n");
		else if (n == -2)
			printf("Wrong:input too big.\n");
		else {
			if (GeneratingSudoku(n))
				printf("Completed Generating!\n");
			else
				printf("Wrong:sudoku.txt doesn't exist.\n");
		}
	}
	else if (strcmp(argv[1], "-s") == 0) {
		FILE* fp;
		errno_t err;
		err = fopen_s(&fp,argv[2], "r");
		if (err!=0)
			printf("Wrong:File open failed.\n");
		else {
			if (SolvingSudoku(fp))
			{
				printf("Successfully solved!\n");
			}
			else {
				printf("Wrong:sudoku.txt doesn't exist.\n");
			}
			fclose(fp);
		}
	}
	else
	{
		printf("Wrong:input wrong.\n");
	}
	return 0;
}