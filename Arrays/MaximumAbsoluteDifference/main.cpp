#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findMinAbsDifference(vector<int> &arr) {
  int min = INT_MAX;
  for (int i = 0; i < arr.size() - 1; i++) {
    int dif = abs(arr[i + 1] - arr[i]);
    min = (min < dif) ? min : dif;
  }
  return min;
}

vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
  vector<vector<int>> result;
  sort(arr.begin(), arr.end());

  int min_dif = findMinAbsDifference(arr);

  for (int i = 0; i < arr.size() - 1; i++) {
    if (abs(arr[i + 1] - arr[i]) == min_dif) {
      vector<int> temp;
      temp.push_back(arr[i]);
      temp.push_back(arr[i + 1]);
      result.push_back(temp);
    }
  }

  return result;
}

int main() {

  vector<int> arr;
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(3);

  vector<vector<int>> result = minimumAbsDifference(arr);

  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
