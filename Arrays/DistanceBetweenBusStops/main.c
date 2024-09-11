#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(const int a, const int b) { return a < b ? a : b; }

int computeClockwiseDistance(int *distance, int distanceSize, int start,
                             int destination) {
  ;
  int clockwiseDistance = 0;
  for (int i = start; i != destination; i = (i + 1) % distanceSize) {
    clockwiseDistance += distance[i];
  }
  return clockwiseDistance;
}

int computeCounterClockwiseDistance(int *distance, int distanceSize, int start,
                                    int destination) {
  int counterClockwiseDistance = 0;
  for (int i = start; i != destination;
       i = (i - 1 + distanceSize) % distanceSize) {
    counterClockwiseDistance += distance[(i - 1 + distanceSize) % distanceSize];
  }
  return counterClockwiseDistance;
}

int distanceBetweenBusStops(int *distance, int distanceSize, int start,
                            int destination) {
  const int clockwiseDistance =
      computeClockwiseDistance(distance, distanceSize, start, destination);
  const int counterClockwiseDistance = computeCounterClockwiseDistance(
      distance, distanceSize, start, destination);
  return min(clockwiseDistance, counterClockwiseDistance);
}

int main() {

  int distance[] = {1, 2, 3, 4};
  int distanceSize = 4;
  int start = 0;
  int destination = 1;

  printf("%d\n",
         distanceBetweenBusStops(distance, distanceSize, start, destination));

  return 0;
}
