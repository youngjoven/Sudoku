#include <iostream>
#include <string>
#include <vector>
#include "Sudoku.h"
using namespace std;
int main()
{
	int number;
	cout << "******************** Choose The Number! ********************" << endl;
	cout << "Only Perfect Square's grids are possible." << endl;
	cout << "For example, 9 for (9X9), 16 for (16X16),, etc" << endl;
	cout << "Warning! 25 grides are possible but it takes long time!" << endl;
	//4 X 4 grids are possible
	//9 x 9 grids are possible
	//16 x 16 grids are possible
	//25 x 25 grids are possible but it takes long time
	cin >> number;
	//in this case, I deleted inputFile and outPutFile
	//because I focused on defining grids of "arbitrary" size
	//That's what the professor expected.
	Sudoku sudoku(number);
	cout << "Grids are setting......" << endl;
	sudoku.solveSudoku();
	sudoku.printSudokuGrid();
	cout << endl;
	system("pause");
	return 0;
}