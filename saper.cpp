#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 8;
const int NUM_MINES = 10;
const char HIDDEN_CELL = '#';
const char MINE_CELL = '*';
const char EMPTY_CELL = ' ';

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, HIDDEN_CELL));
vector<vector<bool>> revealed(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));
vector<vector<bool>> mineLocations(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));

void generateMines() {
    int count = 0;
    while (count < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (!mineLocations[row][col]) {
            mineLocations[row][col] = true;
            count++;
        }
    }
}

bool isValidCell(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

int countAdjacentMines(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (isValidCell(newRow, newCol) && mineLocations[newRow][newCol]) {
                count++;
            }
        }
    }
    return count;
}

void revealCell(int row, int col) {
    if (!isValidCell(row, col) || revealed[row][col]) {
        return;
    }

    revealed[row][col] = true;
    board[row][col] = '0' + countAdjacentMines(row, col);

    if (board[row][col] == '0') {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = row + i;
                int newCol = col + j;
                revealCell(newRow, newCol);
            }
        }
    }
}

void displayBoard(bool revealMines) {
    cout << "  ";
    for (int col = 0; col < BOARD_SIZE; col++) {
        cout << col << " ";
    }
    cout << endl;

    for (int row = 0; row < BOARD_SIZE; row++) {
        cout << row << " ";
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (revealed[row][col] || revealMines) {
                cout << board[row][col] << " ";
            } else {
                cout << HIDDEN_CELL << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(nullptr));

    generateMines();

    int row, col;
    int remainingCells = BOARD_SIZE * BOARD_SIZE - NUM_MINES;
    bool gameOver = false;

    cout << "Welcome to Minesweeper!" << endl;

    while (!gameOver) {
        displayBoard(false);
        cout << "Enter row and column (separated by a space): ";
        cin >> row >> col;

        if (!isValidCell(row, col) || revealed[row][col]) {
            cout << "Invalid move! Please try again." << endl;
            continue;
        }

        if (mineLocations[row][col]) {
            gameOver = true;
            cout << "Game Over! You hit a mine." << endl;
            displayBoard(true);
        } else {
            revealCell(row, col);
            remainingCells--;

            if (remainingCells == 0) {
                gameOver = true;
                cout << "Congratulations! You won the game!" << endl;
                displayBoard(true);
            }
        }
    }

    return 0;
}
