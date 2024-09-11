#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool checkIfPointIsOnLine(const vector<int> &point,
                          const pair<float, float> &lineCoefficients) {
  // y = a * x + b
  // point.y = a * point.x + b
  // point.y = lineCoefficients.first * point.x + lineCoefficients.second
  return static_cast<float>(point[1]) ==
         lineCoefficients.first * static_cast<float>(point[0]) +
             lineCoefficients.second;
}

pair<float, float> getLineCoefficients(const vector<int> &p1,
                                       const vector<int> &p2) {
  // y = a * x + b
  // p1.y = a * p1.x + b
  // p2.y = a * p2.x + b
  const float a =
      static_cast<float>(p2[1] - p1[1]) / static_cast<float>(p2[0] - p1[0]);
  const float b = static_cast<float>(p1[1]) - a * static_cast<float>(p1[0]);
  return make_pair(a, b);
}

bool checkVerticalLine(const vector<vector<int>> &coordinates) {
  for (int i = 1; i < coordinates.size(); i++)
    if (coordinates[i][0] != coordinates[0][0])
      return false;
  return true;
}

bool checkVerticalLineEdgeCase(const vector<vector<int>> &coordinates) {
  // check if the first two points are on the same vertical line
  if (coordinates[0][0] != coordinates[1][0])
    return true;

  // check if the rest of the points are on the same vertical line
  for (int i = 2; i < coordinates.size(); i++)
    if (coordinates[i][0] != coordinates[0][0])
      return false;

  return true;
}

bool checkStraightLine(vector<vector<int>> &coordinates) {
  if (coordinates.size() == 2)
    return true;

  // check for vertical line
  if (checkVerticalLine(coordinates))
    return true;

  // check for vertical line edge case when the first two points are on the same
  // vertical line
  if (!checkVerticalLineEdgeCase(coordinates))
    return false;

  const pair<float, float> lineCoefficients =
      getLineCoefficients(coordinates[0], coordinates[1]);

  for (int i = 2; i < coordinates.size(); i++)
    if (!checkIfPointIsOnLine(coordinates[i], lineCoefficients))
      return false;

  return true;
}

int main() {

  vector<vector<int>> coordinates;
  vector<int> temp;

  temp.push_back(1);
  temp.push_back(2);
  coordinates.push_back(temp);
  temp.clear();

  temp.push_back(2);
  temp.push_back(3);
  coordinates.push_back(temp);
  temp.clear();

  temp.push_back(3);
  temp.push_back(4);
  coordinates.push_back(temp);
  temp.clear();

  temp.push_back(4);
  temp.push_back(5);
  coordinates.push_back(temp);
  temp.clear();

  temp.push_back(5);
  temp.push_back(6);
  coordinates.push_back(temp);
  temp.clear();

  temp.push_back(6);
  temp.push_back(7);
  coordinates.push_back(temp);
  temp.clear();

  cout << checkStraightLine(coordinates) << endl;

  return 0;
}
