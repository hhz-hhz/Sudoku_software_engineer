#include<stdlib.h>
#include<string.h>
#include"DefiningBeginning.h"
#include"GeneratingSudoku.h"
#include"SolvingSudoku.h"
#include"sudoku.h"

int sudoku(int argc, char* argv[])
{
	if (strcmp(argv[1], "-c") == 0)
	{
		int n = ChageStringToNumber(argv[2]);

		if (n == -1 || n == 0)
		{
			printf("Wrong:input wrong.\n");
			return 5;
		}
		else if (n == -2)
		{
			printf("Wrong:input too big.\n");
			return 5;
		}
		else {
			if (GeneratingSudoku(n))
				printf("Completed Generating!\n");
			else
				printf("Wrong:sudoku.txt doesn't exist.\n");
		}
		return 1;
	}
	else if (strcmp(argv[1], "-s") == 0) {

		FILE* fp;
		errno_t err;
		err = fopen_s(&fp, argv[2], "r");
		if (err != 0)
		{
			printf("Wrong:File open failed.\n");
			return 4;
		}
		else {
			if (SolvingSudoku(fp))
			{
				printf("Successfully solved!\n");
			}
			else {
				printf("Wrong:sudoku.txt doesn't exist.\n");
			}
			if (fp != 0)fclose(fp);
		}
		return 2;
	}
	else
	{
		printf("Wrong:input wrong.\n");
		return 3;
	}
}