#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for(int i = 0; i < 9; i++) {
        // Check row (9 * 9 board)
        if(board[row][i] == num) {
            return false;
        }
        
        // Check column (9 * 9 board)
        if(board[i][col] == num) {
            return false;
        }

        // Check 3x3 board
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if(board[row][col] == '.') {
                for(char num = '1'; num <= '9'; num++) {
                    if(isValid(board, row, col, num) == true) { // if valid
                        board[row][col] = num;
                        if(solveSudoku(board)) {
                            return true;
                        } else {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main() {
    vector<vector<char>> sudokuGrid(9, vector<char>(9));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudokuGrid[i][j];
        }
    }

    if (solveSudoku(sudokuGrid)) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudokuGrid[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
