#pragma once
/* notes
sudoku()
default constructor
precondition : none
postcondition: grid is initialized to 0

sudoku(g[][9])
1-parameter constructor
precondition : g satisfies sudoku grid restrictions
postcondition: grid = g

void initialiizeSudokuGrid()
interactive function to prompt the user to specify the number of the partially filled grid
precondition : none
postcondition: grid is initialized to the number specified by the user

void initializeSudokuGrid(int g[][9])
function to initialize grid to g
precondition:  g satisties sudoku grid restrictions
postcondition: grid = g

void printSudokuGrid()
function to print the sudoku

bool solveSudoku()
function to solve thesukoku problem
precondition : none
postcondition: if a solution exists, it returns true, otherwise it returns false

bool findEmptyGridSlot(int &row, int &col)
function to determine if the grid slot specified by row and col is empty
precondition : row and col refer to a grid slot
postcondition: returns true if grid[row][col] = 0, otherwise it returns false

bool canPlaceNum(int row, int col, int num)
function to determine if num can be placed in grid[row][col]
precondition : row and col refer to a grid slot
postcondition: returns true if num can be placed in grid[row][col], otherwise it returns false

bool numAlreadyInRow(int row, int num)
function to determine if num is in grid[row][]
precondition : row refers to a grid row and num is an integer inclusively between 1 and 9
postcondition: returns true if num is in grid[row][], otherwise it returns false

bool numAlreadyInCol(int col, int num)
function to determine if num is in grid[row][]
precondition : col refers to a grid column and num is an integer inclusively between 1 and 9
postcondition: returns true if num is in grid[][col], otherwise it returns false

bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
function to determine if num is in the small grid that contains grid[smallGridRow][smallGridCol]
precondition : smallGridRow and smallGridCol refer to a grid slot, num is an integer inclusively between 1 and 9
postcondition: returns true if num is in small grid, otherwise it returns false
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
class Sudoku
{
public:
	Sudoku(int size);
	void initializeSudokuGrid();
	void printSudokuGrid();
	bool solveSudoku();
	bool findEmptyGridSlot(int &row, int &col);
	bool canPlaceNum(int row, int col, int num);
	bool numAlreadyInRow(int row, int num);
	bool numAlreadyInCol(int col, int num);
	bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
	//Changed below functions and constructors
	Sudoku(vector<vector<int>> g, int size);
	Sudoku(ifstream& configuration, int size);
	void initializeSudokuGrid(vector<vector<int>>g);
	void printFinalSudokuGrid(ofstream &outPutFile);
	bool perfectSquare(int n);
	void wrong();
private:
	vector<vector<int>> grid;
	int gridSize;
	int smallSize;
};
