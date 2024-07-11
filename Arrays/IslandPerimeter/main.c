#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
  int isVisited, sideCount, isLand;
} POINT;

POINT createPoint() { return (POINT){0, 0, 0}; }

void countSides(POINT **grid, int gridSize, int *gridColSize, int x, int y) {
  // check NSWE directions, if they are out of bounds or water

  // N
  if (x == 0 || grid[x - 1][y].isLand == 0)
    grid[x][y].sideCount++;

  // S
  if (x + 1 == gridSize || grid[x + 1][y].isLand == 0)
    grid[x][y].sideCount++;

  // W
  if (y == 0 || grid[x][y - 1].isLand == 0)
    grid[x][y].sideCount++;

  // E
  if (y + 1 == *gridColSize || grid[x][y + 1].isLand == 0)
    grid[x][y].sideCount++;
}

POINT **createGrid(int **grid, int rows, int cols) {
  POINT **pointGrid = (POINT **)malloc(rows * sizeof(POINT *));
  for (int i = 0; i < rows; i++) {
    pointGrid[i] = (POINT *)malloc(cols * sizeof(POINT));
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pointGrid[i][j] = createPoint();
      pointGrid[i][j].isLand = grid[i][j];
    }
  }

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      countSides(pointGrid, rows, &cols, i, j);

  return pointGrid;
}

void printGrid(POINT **grid, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", grid[i][j].isLand);
    }
    printf("\n");
  }
}

void getStart(POINT **grid, int gridSize, int *gridColSize, int *start_x,
              int *start_y) {
  *start_x = -1;
  *start_y = -1;

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j].isLand == 1) {
        *start_x = i;
        *start_y = j;
        return;
      }
    }
  }
}

void fill(POINT **grid, int gridSize, int *gridColSize, int x, int y,
          int *perimeter) {

  if (x == -1 || x == gridSize || y == -1 || y == *gridColSize)
    return;

  if (grid[x][y].isVisited || !grid[x][y].isLand) {
    return;
  }

  printf("x: %d | y : %d | sides: %d\n", x, y, grid[x][y].sideCount);

  grid[x][y].isVisited = 1;
  (*perimeter) += grid[x][y].sideCount;

  // N
  fill(grid, gridSize, gridColSize, x - 1, y, perimeter);

  // S
  fill(grid, gridSize, gridColSize, x + 1, y, perimeter);

  // W
  fill(grid, gridSize, gridColSize, x, y - 1, perimeter);

  // E
  fill(grid, gridSize, gridColSize, x, y + 1, perimeter);
}

int islandPerimeter(int **grid, int gridSize, int *gridColSize) {

  POINT **pointGrid = createGrid(grid, gridSize, *gridColSize);

  printGrid(pointGrid, gridSize, *gridColSize);

  // search for the first land
  int start_x, start_y;
  getStart(pointGrid, gridSize, gridColSize, &start_x, &start_y);
  if (start_x == -1 && start_y == -1)
    return 0;

  int perimeter = 0;

  fill(pointGrid, gridSize, gridColSize, start_x, start_y, &perimeter);

  return perimeter;
}

int main(void) {
  int gridSize = 4;
  int gridColSize = 4;

  int **grid = (int **)malloc(MAX_ROWS * sizeof(int *));
  for (int i = 0; i < MAX_ROWS; i++) {
    grid[i] = (int *)malloc(MAX_COLS * sizeof(int));
  }

  int data[MAX_ROWS][MAX_COLS] = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      grid[i][j] = data[i][j];
    }
  }

  printf("%d", islandPerimeter(grid, gridSize, &gridColSize));

  return 0;
}
