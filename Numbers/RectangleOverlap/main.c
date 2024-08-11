#include <stdbool.h>

bool isRectangleOverlap(int *rec1, int rec1Size, int *rec2, int rec2Size) {
  // Check for the overlap in horizontal and vertical directions
  bool horizontal_overlap = !(rec2[0] >= rec1[2] || rec2[2] <= rec1[0]);
  bool vertical_overlap = !(rec2[1] >= rec1[3] || rec2[3] <= rec1[1]);

  // The rectangles overlap if they overlap both horizontally and vertically
  return horizontal_overlap && vertical_overlap;
}
