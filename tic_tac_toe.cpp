#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameOver;
    int movesCount;

public:
    TicTacToe() {
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        currentPlayer = 'X';
        gameOver = false;
        movesCount = 0;
    }

    void displayBoard() const {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    bool makeMove(int boxNum) {
        int row = (boxNum - 1) / 3;
        int col = (boxNum - 1) % 3;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            movesCount++;
            if (checkGameStatus(row, col)) {
                gameOver = true;
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (movesCount == 9) {
                gameOver = true;
                displayBoard();
                cout << "It's a draw!" << endl;
            }
            switchPlayer();
            return true;
        }
        return false;
    }

    bool isValidMove(int row, int col) const {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid move! Box number should be between 1 and 9." << endl;
            return false;
        }
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! That cell is already occupied." << endl;
            return false;
        }
        return true;
    }

    bool checkGameStatus(int row, int col) const {
        // Check rows, columns, and diagonals for a win
        if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer) {
            return true;
        }
        if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) {
            return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool isGameOver() const {
        return gameOver;
    }

private:
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;
    int boxNum;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (box number 1-9): ";
        cin >> boxNum;

    } while (!game.makeMove(boxNum) || !game.isGameOver());

    cout << "Game Over!" << endl;

    return 0;
}
