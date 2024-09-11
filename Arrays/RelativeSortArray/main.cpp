#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
  map<int, int> map;
  for (auto i : arr1)
    map[i]++;

  vector<int> result(arr1.size());
  int index = 0;

  for (auto item : arr2) {
    for (int i = 0; i < map[item]; i++) {
      cout << item << " ";
      result[index++] = item;
    }

    cout << endl;
    map.erase(item);
  }

  for (auto i : map) {
    for (int j = 0; j < i.second; j++) {
      result[index++] = i.first;
    }
  }

  return result;
}

int main() {
  vector<int> arr1;
  vector<int> arr2;

  arr1.push_back(2);
  arr1.push_back(3);
  arr1.push_back(1);
  arr1.push_back(3);
  arr1.push_back(2);
  arr1.push_back(4);
  arr1.push_back(6);
  arr1.push_back(7);
  arr1.push_back(9);
  arr1.push_back(2);
  arr1.push_back(19);

  arr2.push_back(2);
  arr2.push_back(1);
  arr2.push_back(4);
  arr2.push_back(3);
  arr2.push_back(9);
  arr2.push_back(6);

  vector<int> result = relativeSortArray(arr1, arr2);

  for (auto i : result) {
    cout << i << " ";
  }

  return 0;
}
