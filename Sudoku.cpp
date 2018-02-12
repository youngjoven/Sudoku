#include <iostream>
#include <string>
#include <vector>
//Math for Square root
#include <math.h>
#include <iomanip>
#include "sudoku.h"
using namespace std;
//Constructor
//int size is necessary for perfect Square
Sudoku::Sudoku(int size)
{
	//The criterion that must be met is 
	//that the grid dimension be a perfect square
	bool var = perfectSquare(size);
	if (var)
	{
		gridSize = size;
		smallSize = int(sqrt(size));
		grid = vector<vector<int>>(gridSize, vector<int>(gridSize));
		initializeSudokuGrid();
	}
	else
	{
		wrong();
	}
}
Sudoku::Sudoku(std::vector< std::vector<int> > g, int size)
{
	gridSize = size;
	//replace the 2D arrays with vectors
	grid = vector< vector<int> >(gridSize, vector<int>(gridSize));
	initializeSudokuGrid(g);
}
void Sudoku::initializeSudokuGrid()
{

	for (int row = 0; row < gridSize; row++)
		for (int col = 0; col < gridSize; col++)
			grid[row][col] = 0;
}
void Sudoku::initializeSudokuGrid(vector<vector<int>>g)
{
	for (int row = 0; row < gridSize; row++)
		for (int col = 0; col < gridSize; col++)
			grid[row][col] = g[row][col];
}
void Sudoku::printSudokuGrid()
{
	for (int row = 0; row < gridSize; row++)
	{
		for (int col = 0; col < gridSize; col++)
			//Clarify Sudoku number using setw
			cout << setw(5) << grid[row][col];
		cout << endl;
	}
	cout << endl;
}
bool Sudoku::solveSudoku()
{
	int row = 0, col = 0;
	if (findEmptyGridSlot(row, col))
	{
		for (int num = 1; num <= gridSize; num++)
		{
			if (canPlaceNum(row, col, num))
			{
				grid[row][col] = num;
				if (solveSudoku())
					return true;
				grid[row][col] = 0;
			}
		}
		return false;
	}
	else
		return true;
}
bool Sudoku::findEmptyGridSlot(int &row, int &col)
{
	for (row = 0; row < gridSize; row++)
		for (col = 0; col < gridSize; col++)
			if (grid[row][col] == 0)
				return true;
	row = -1;
	col = -1;
	return false;
}
bool Sudoku::canPlaceNum(int row, int col, int num)
{
	return !numAlreadyInRow(row, num) &&
		!numAlreadyInCol(col, num) &&
		!numAlreadyInBox(row, col, num);
}
bool Sudoku::numAlreadyInRow(int row, int num)
{
	for (int col = 0; col < gridSize; col++)
		if (grid[row][col] == num) return true;
	return false;
}
bool Sudoku::numAlreadyInCol(int col, int num)
{
	for (int row = 0; row < gridSize; row++)
		if (grid[row][col] == num) return true;
	return false;
}
bool Sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{

	int beginSmallGridRow = smallGridRow - smallGridRow % smallSize;
	int endSmallGridRow = beginSmallGridRow + smallSize;
	int beginSmallGridCol = smallGridCol - smallGridCol % smallSize;
	int endSmallGridCol = beginSmallGridCol + smallSize;

	for (int row = beginSmallGridRow; row < endSmallGridRow; row++)
		for (int col = beginSmallGridCol; col < endSmallGridCol; col++)
			if (grid[row][col] == num)
				return true;
	return false;
}
//add a constructor to the Sudoku class that reads the initial configuration from a file
Sudoku::Sudoku(ifstream& configuration, int size)
{
	gridSize = size;
	grid = vector< vector<int> >(gridSize, vector<int>(gridSize));
	int value;
	for (int row = 0; row < gridSize; row++)
		for (int col = 0; col < gridSize; col++) {
			configuration >> value;
			grid[row][col] = value;
		}
}
//I don't use this function well because I focused on the perfect square.
void Sudoku::printFinalSudokuGrid(ofstream &outPutFile)
{
	solveSudoku();
	printSudokuGrid();
	cout << "Final sudoku in txt file is completed." << endl;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
			outPutFile << setw(3) << grid[row][col];
		outPutFile << endl;
	}
}
//This will help sizing perfectSqare.
bool Sudoku::perfectSquare(int n)
{
	//defines grids of "arbitrary" size.
	int num = int(sqrt(n));
	if (num * num != n)
	{
		cout << "It is not perfect Square!" << endl;

		return false;
	}
	return true;
}
//This is wrong function for catching wrong answer from user.
void Sudoku::wrong()
{
	gridSize = 9;
	grid = vector<vector<int>>(gridSize, vector<int>(gridSize));
	smallSize = 3;
	cout << "This is wrong. Try again after exit" << endl;
	cout << "The grids should be Perfect Square. " << endl;
	cout << "For example, look at this 9 for 9 X 9" << endl;
	initializeSudokuGrid();

}