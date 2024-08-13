#include <stdbool.h>

void findRook(char **board, int boardSize, int *boardColSize, int *row,
              int *col) {
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardColSize[i]; j++) {
      if (board[i][j] == 'R') {
        *row = i;
        *col = j;
        return;
      }
    }
  }

  *row = -1;
  *col = -1;
}

bool checkUp(char **board, int boardSize, int *boardColSize, int row, int col) {
  bool foundPawn = false;
  for (int i = row - 1; i >= 0; i--) {
    if (board[i][col] == 'B') {
      break;
    } else if (board[i][col] == 'p') {
      foundPawn = true;
    }
  }

  return foundPawn;
}

bool checkDown(char **board, int boardSize, int *boardColSize, int row,
               int col) {
  bool foundPawn = false;
  for (int i = row + 1; i < boardSize; i++) {
    if (board[i][col] == 'B') {
      break;
    } else if (board[i][col] == 'p') {
      foundPawn = true;
    }
  }

  return foundPawn;
}

bool checkLeft(char **board, int boardSize, int *boardColSize, int row,
               int col) {
  bool foundPawn = false;
  for (int i = col - 1; i >= 0; i--) {
    if (board[row][i] == 'B') {
      break;
    } else if (board[row][i] == 'p') {
      foundPawn = true;
    }
  }

  return foundPawn;
}

bool checkRight(char **board, int boardSize, int *boardColSize, int row,
                int col) {
  bool foundPawn = false;
  for (int i = col + 1; i < boardColSize[row]; i++) {
    if (board[row][i] == 'B') {
      break;
    } else if (board[row][i] == 'p') {
      foundPawn = true;
    }
  }

  return foundPawn;
}

int numRookCaptures(char **board, int boardSize, int *boardColSize) {
  // . or , for empty space
  // p for pawn
  // R for rook
  // B for bishop

  // Find the rook
  int rookRow, rookCol;
  findRook(board, boardSize, boardColSize, &rookRow, &rookCol);

  return checkUp(board, boardSize, boardColSize, rookRow, rookCol) +
         checkDown(board, boardSize, boardColSize, rookRow, rookCol) +
         checkLeft(board, boardSize, boardColSize, rookRow, rookCol) +
         checkRight(board, boardSize, boardColSize, rookRow, rookCol);
}
