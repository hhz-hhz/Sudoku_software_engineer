#ifndef __DEFININGBEGINNING__
#define __DEFININGBEGINNING__

#define SIZE 9
#include<iostream>
using namespace std;

//sudoku structure
typedef struct {
	int map[SIZE][SIZE];
}SUDOKU;

class DefineBeginning
{
public:
	DefineBeginning() {};

	//change string to number
	//return -1: not number  -2: over request
	int ChageStringToNumber(char s[]);

	//write puts to file
	//void WritePutsToFile(FILE* fp, SUDOKU m);

	void WritePutsToFile(FILE* fp, SUDOKU m);

};
#endif // !__DEFININGBEGINNING__
