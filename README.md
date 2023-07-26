# Minesweeper Game

This is a simple implementation of the classic Minesweeper game in C++. The game is played on an 8x8 board where the player's goal is to reveal all cells that do not contain mines without clicking on a mine. The game will end if the player clicks on a mine or successfully reveals all non-mine cells.

## Rules

1. The game starts with a hidden board where all cells are covered.
2. The player can enter the row and column of the cell they want to reveal.
3. If the revealed cell contains a mine, the game ends, and the player loses.
4. If the revealed cell does not contain a mine, it will display the number of adjacent cells that contain mines.
5. If the revealed cell has no adjacent mines, it will automatically reveal all neighboring cells recursively until cells with adjacent mines are found.
6. The game ends when all non-mine cells are revealed, and the player wins.

## How to Play

1. Run the program, and you will see the initial hidden board.
2. The board is represented by a grid of numbers and characters:
   - "#" represents a hidden cell.
   - "*" represents a mine.
   - " " (space) represents an empty cell.
   - Numbers (0 to 8) indicate the number of adjacent mines for a revealed cell.
3. Enter the row and column of the cell you want to reveal when prompted. Rows and columns are 0-indexed, so valid input ranges from 0 to 7 for both.
4. The game will display the updated board after each move.
5. If you reveal a cell containing a mine, the game ends, and you lose. The board will be revealed, showing all mine locations.
6. If you successfully reveal all non-mine cells, you win the game, and the board will be revealed, showing all cells and their mine counts.

## Code Overview

1. The code uses three 2D vectors (`board`, `revealed`, and `mineLocations`) to represent the game board, the state of cell revealings, and the locations of mines, respectively.
2. The function `generateMines()` randomly places 10 mines on the board.
3. `isValidCell()` checks if a given row and column are within the bounds of the board.
4. `countAdjacentMines()` calculates the number of mines adjacent to a given cell.
5. `revealCell()` recursively reveals cells and their adjacent cells when an empty cell is revealed.
6. `displayBoard()` displays the current state of the board, either revealing all cells (for end game) or hiding some cells (during the game).
7. In `main()`, the game loop continues until the game is over. The player is prompted for their move (row and column), and the appropriate actions are taken based on the input.

Remember, compile and run the code to play Minesweeper! Have fun!
