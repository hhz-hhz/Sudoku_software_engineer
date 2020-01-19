#include<iostream>
using namespace std;
#include <string.h>
#include <ctype.h>
#include "DefiningBeginning.h"


//return number after command '-c' 
//isdigit(s[i])jugde if number or not
int DefineBeginning::ChageStringToNumber(char s[])
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

//quick write 
void DefineBeginning::WritePutsToFile(FILE* fp, SUDOKU m)
{
	int p = 0;
	char t[164];
	memset(t, 0, sizeof(t));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			t[p] = m.map[i][j] + '0';
			p++;
			if (j != 8)
			{
				t[p] = ' ';
				p++;
			}
		}
		t[p] = '\n';
		p++;
	}
	t[p] = '\n';
	fputs(t, fp);
}