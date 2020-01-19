#ifndef __SOLVINGSUDOKU__
#define __SOLVINGSUDOKU__
#include<iostream>
using namespace std;
class SolveSudoku
{
public:
	SolveSudoku() {};

	//solve sudoku 
	//return bool to false or success
	bool SolvingSudoku(FILE* rfp);

};
#endif // !__SOLVINGSUDOKU__