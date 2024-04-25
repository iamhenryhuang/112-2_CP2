#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudokuBruteForce(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        return true; // All rows completed
    }
    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col == 8) ? 0 : col + 1;
    
    if (board[row][col] != '.') {
        return solveSudokuBruteForce(board, nextRow, nextCol);
    }

    for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudokuBruteForce(board, nextRow, nextCol)) {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;
}

int main() {
    vector<vector<char>> sudokuGrid(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudokuGrid[i][j];
        }
    }

    if (solveSudokuBruteForce(sudokuGrid, 0, 0)) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudokuGrid[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
