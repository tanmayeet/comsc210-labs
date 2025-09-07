#include <stdbool.h>
#include <stdio.h>

#define WHITE 'W'
#define BLACK 'B'
#define EMPTY 'U'

void printBoard(char board[][26], int n) {
  char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                     'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  printf("  ");
  for (int i = 0; i < n; i++) {
    printf("%c", alphabet[i]);
  }
  printf("\n");

  //   for(int j = 0; j < n; j++){
  //     printf("%c\n", alphabet[j]);
  //   }

  for (int i = 0; i < n; i++) {
    printf("%c", alphabet[i]);
    printf(" ");
    for (int j = 0; j < n; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {
  return (row >= 0 && row < n && col >= 0 && col < n);
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char color, int deltaRow, int deltaCol) {
  // checks for the other's color
  char other;
  if (color == WHITE) {
    other = BLACK;
  } else {
    other = WHITE;
  }

  // move one step in a given direction
  int i = row + deltaRow;
  int j = col + deltaCol;
  bool found = false;

  // checks whether the adjacent cells are w/n the bounds
  if (!positionInBounds(n, i, j)) {
    return false;
  }

  // checks whether the adjacent cells are not the others
  if (board[i][j] != other) {
    return false;
  }
  found = true;  // after checking those conditions itll proceed

  // continues checking whether adjacent cell is opponent's color --> illegal if
  // so
  while (positionInBounds(n, i + deltaRow, j + deltaCol)) {
    i += deltaRow;
    j += deltaCol;

    if (board[i][j] == EMPTY) {
      return false;
    }
    if (board[i][j] == color) {
      return found;
    }
    if (board[i][j] == other) {
      found = true;
    }
  }
  return false;
}

void printAvailableMoves(char board[][26], int dimension, char color) {
  printf("Available moves for %c:\n", color);
  for (int row = 0; row < dimension; row++) {
    for (int col = 0; col < dimension; col++) {
      if (board[row][col] == 'U') {
        bool legalMove = false;
        for (int newRow = -1; newRow <= 1; newRow++) {
          for (int newCol = -1; newCol <= 1; newCol++) {
            if (!(newRow == 0 && newCol == 0)) {
              if (checkLegalInDirection(board, dimension, row, col, color,
                                        newRow, newCol)) {
                legalMove = true;
                break;
              }
            }
          }
          if (legalMove) {
            break;
          }
        }

        if (legalMove) {
          printf("%c%c\n", (char)('a' + row), (char)('a' + col));
        }
      }
    }
  }
}

void flipTilesInDirection(char board[][26], int n, int row, int col, char color,
                          int deltaRow, int deltaCol) {
  char opponentColor;
  if (color == WHITE) {
    opponentColor = BLACK;
  } else {
    opponentColor = WHITE;
  }

  int i = row + deltaRow;
  int j = col + deltaCol;
  bool foundMyOpp = false;
  int tilesToFlip[26 * 26][2];
  int tilesFlipped = 0;

  if (!positionInBounds(n, i, j)) {
    return;
  }

  if (board[i][j] != opponentColor) {
    return;
  }
  foundMyOpp = true;
  tilesToFlip[tilesFlipped][0] = i;
  tilesToFlip[tilesFlipped][1] = j;
  tilesFlipped++;

  while (positionInBounds(n, i + deltaRow, j + deltaCol)) {
    i += deltaRow;
    j += deltaCol;

    if (board[i][j] == EMPTY) {
      return;
    }
    if (board[i][j] == color) {
      for (int tile = 0; tile < tilesFlipped; tile++) {
        board[tilesToFlip[tile][0]][tilesToFlip[tile][1]] = color;  // Flip them
      }
      return;
    }
    if (board[i][j] == opponentColor) {
      foundMyOpp = true;
      tilesToFlip[tilesFlipped][0] = i;
      tilesToFlip[tilesFlipped][1] = j;
      tilesFlipped++;
    }
  }
  return;  // Ran out of bounds or we never found a tile of our own
}

int main(void) {
  int dimension;
  printf("Enter the board dimension: ");
  scanf("%d", &dimension);
  char board[26][26];

  // initializes the board with pieces in correct places based on dimensions and
  // with the lettering on the sides
  for (int row = 0; row < dimension; row++) {
    for (int col = 0; col < dimension; col++) {
      if ((row == (dimension / 2) - 1 && col == (dimension / 2) - 1) ||
          (row == (dimension / 2) && col == (dimension / 2))) {
        board[row][col] = WHITE;  // Black tiles
      } else if ((row == (dimension / 2) - 1 && col == (dimension / 2)) ||
                 (row == (dimension / 2) && col == (dimension / 2) - 1)) {
        board[row][col] = BLACK;
      } else {
        board[row][col] = EMPTY;
      }
    }
  }

  printBoard(board, dimension);

  char color, rowChar, colChar;

  // takes in input for config and changes the board using ascii characters
  printf("Enter board configuration:\n");
  while (true) {
    scanf(" %c%c%c", &color, &rowChar, &colChar);

    if (color == '!' && rowChar == '!' && colChar == '!') {
      break;
    }

    board[rowChar - 'a'][colChar - 'a'] = color;
    // printf("rowChar: %d\n", rowChar);
    // printf("colChar: %d\n", colChar);
    // printf("%d\n", rowChar - 'a');
    // printf("%d", colChar - 'a');
  }
  printBoard(board, dimension);
  printAvailableMoves(board, dimension, WHITE);
  printAvailableMoves(board, dimension, BLACK);

  char finalColor, row, col;
  printf("Enter a move:\n");
  scanf(" %c%c%c", &finalColor, &row, &col);
  int finalRow = row - 'a';
  int finalCol = col - 'a';

  bool legalMove = false;

  for (int a = -1; a <= 1; a++) {
    for (int b = -1; b <= 1; b++) {
      if (!(a == 0 && b == 0)) {
        if (checkLegalInDirection(board, dimension, finalRow, finalCol,
                                  finalColor, a, b)) {
          legalMove = true;
          break;
        }
      }
    }
    if (legalMove) {
      break;
    }
  }

  if (legalMove && positionInBounds(dimension, finalRow, finalCol)) {
    printf("Valid move.\n");
    board[finalRow][finalCol] = finalColor;

    // Flip tiles in all valid directions (-1, 0, 1)
    for (int a = -1; a <= 1; a++) {
      for (int b = -1; b <= 1; b++) {
        if (!(a == 0 && b == 0)) {
          if (checkLegalInDirection(board, dimension, finalRow, finalCol,
                                    finalColor, a, b)) {
            flipTilesInDirection(board, dimension, finalRow, finalCol,
                                 finalColor, a, b);
          }
        }
      }
    }
  } else {
    printf("Invalid move.\n");  // won't flip the tiles if its an invalid move
  }
  // prints final board
  printBoard(board, dimension);

  return 0;
}