#include "pch.h"
#include "CppUnitTest.h"
#include "../sudoku/DefiningBeginning.h"
#include "../sudoku/GeneratingSudoku.h"
#include "../sudoku/SolvingSudoku.h"
#include "../sudoku/sudoku.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		//test ChageStringToNumber
		TEST_METHOD(TestMethod1)
		{
			char* s = "80";
			int except = 80;
			int getresult = ChageStringToNumber(s);
			Assert::AreEqual(except, getresult);
		}
		TEST_METHOD(TestMethod2)
		{
			char* s = "80aaa";
			int except = -1;
			int getresult = ChageStringToNumber(s);
			Assert::AreEqual(except, getresult);
		}
		TEST_METHOD(TestMethod3)
		{
			char* s = "1200000";
			int except = -2;
			int getresult = ChageStringToNumber(s);
			Assert::AreEqual(except, getresult);
		}
		//test SolvingSudoku
		TEST_METHOD(TestMethod4)
		{
			FILE* fp;
			errno_t err;
			char* argv = "testsolve.txt";
			err = fopen_s(&fp, "testsolve.txt", "r");
			if (err != 0)
				Assert::AreEqual(1 == 2, true);
			if (SolvingSudoku(fp))
			{
				FILE* rfile;
				errno_t errr;
				errr = fopen_s(&rfile, "sudoku.txt", "r");
				if (errr != 0)
					Assert::AreEqual(1 == 2, true);
				int result_matrix[9][9];
				int expect_matrix[9][9];
				bool flag = true;
				for (int j = 0; j < 9; j++)
				{
					for (int k = 0; k < 9; k++)
					{
						fscanf_s(rfile, "%d", &result_matrix[j][k]);
					}
				}
				for (int k = 0; k < 9; k++)
				{
					for (int l = 0; l < 9; l++)
					{
						if (result_matrix[k][l] != expect_matrix[k][l])flag = false;
					}
				}
				if (flag)
					Assert::AreEqual(1 == 2, true);
			}
			else {
				Assert::AreEqual(1 == 2, true);
			}
			
		}
		//test GeneratingSudoku
		TEST_METHOD(TestMethod5)
		{
			
			GeneratingSudoku(10);
			FILE* rfile;
			errno_t err;
			err = fopen_s(&rfile, "sudoku.txt", "r");
			if (err != 0)
				Assert::AreEqual(1 == 2, true);
			else
			{
				//read the output file and put the results in a very large matrix, then compare each other 
				int result_matrix[10][9][9];
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						for (int k = 0; k < 9; k++)
						{
							fscanf_s(rfile, "%d", &result_matrix[i][j][k]);
						}
					}
				}
				bool flag = true;
				for (int i = 0; i < 10 - 1; i++)
				{
					for (int j = i + 1; j < 10; j++)
					{
						for (int k = 0; k < 9; k++)
						{
							for (int l = 0; l < 9; l++)
							{
								if (result_matrix[i][k][l] != result_matrix[j][k][l])flag = false;
							}
						}
						if (flag)
							Assert::AreEqual(1 == 2, true);
					}
				}
			}
		}
		
		TEST_METHOD(TestMethod6)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "20";
			int result = sudoku(argc,argv1);
			int except = 1;
			Assert::AreEqual(except == result, true);
		}

		TEST_METHOD(TestMethod7)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-s";
			argv1[2] = "testsolve.txt";
			int result = sudoku(argc, argv1);
			int except = 2;
			Assert::AreEqual(except == result, true);
		}
		TEST_METHOD(TestMethod8)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-p";
			argv1[2] = "20";
			int result = sudoku(argc, argv1);
			int except = 3;
			Assert::AreEqual(except == result, true);
		}

		TEST_METHOD(TestMethod9)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "1200000";
			int result = sudoku(argc, argv1);
			int except = 5;
			Assert::AreEqual(except == result, true);
		}

		TEST_METHOD(TestMethod10)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "20a";
			int result = sudoku(argc, argv1);
			int except = 5;
			Assert::AreEqual(except == result, true);
		}

		TEST_METHOD(TestMethod11)
		{
			int argc;
			char* argv1[3];
			argc = 3;
			argv1[0] = "sudoku.exe";
			argv1[1] = "-s";
			argv1[2] = "testsol.txt";
			int result = sudoku(argc, argv1);
			int except = 4;
			Assert::AreEqual(except == result, true);
		}
	};
}
