#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board, int col, int n) {
    if (col == n) {
        printBoard(board, n);
        return true;
    }

    bool found = false;

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';

            found = solve(board, col + 1, n) || found;

            board[row][col] = '.';
        }
    }

    return found;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    if (!solve(board, 0, n)) {
        cout << "No solution exists" << endl;
    }

    return 0;
}

