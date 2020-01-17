#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "DefiningBeginning.h"


//return number after command '-c' 
int ChageStringToNumber(char s[])
{
	int len = strlen(s);
	int n = 0;

	for (int i = 0; i < len; i++)
	{
		if (!isdigit(s[i]))
			return -1;
		n = n * 10 + s[i] - '0';
	}
	if (len > 8 || n > 1000000)
		return -2;
	return n;
}

void WritePutsToFile(FILE* fp, SUDOKU m)
{
	for (int i = 0; i < 9; i++)
	{
		fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", m.map[i][0], m.map[i][1], m.map[i][2], m.map[i][3], m.map[i][4], m.map[i][5], m.map[i][6], m.map[i][7], m.map[i][8]);
	}
	fprintf(fp, "\n");
}