#include <algorithm> // For sort()
#include <vector>

using namespace std;

vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                      int cCenter) {
  // Step 1: Generate all cells in the matrix
  vector<vector<int>> cells;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cells.push_back({r, c});
    }
  }

  // Step 2: Sort cells by Manhattan distance
  sort(cells.begin(), cells.end(),
       [rCenter, cCenter](const vector<int> &a, const vector<int> &b) {
         int distA = abs(a[0] - rCenter) + abs(a[1] - cCenter);
         int distB = abs(b[0] - rCenter) + abs(b[1] - cCenter);
         return distA < distB;
       });

  return cells;
}
