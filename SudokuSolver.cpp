#include <iostream>
using namespace std;

#define SIZE 9

// Print Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    cout << "\nSolved Sudoku:\n\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check row
bool usedInRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Check column
bool usedInCol(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Check 3x3 box
bool usedInBox(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + startRow][col + startCol] == num)
                return true;
    return false;
}

// Check if safe
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

// Find empty cell
bool findEmpty(int grid[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; row++)
        for (col = 0; col < SIZE; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

// Solve Sudoku using Backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!findEmpty(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int grid[SIZE][SIZE];

    cout << "Enter Sudoku (0 for empty cells):\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nSolving Sudoku... please wait\n";

    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "? No solution exists\n";

    return 0;
}
