#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<int, int> createMap(const vector<int> &arr) {
  unordered_map<int, int> map;
  for (auto i : arr)
    map[i]++;
  return map;
}

unordered_set<int> createSet(const unordered_map<int, int> &map) {
  unordered_set<int> set;
  for (auto i : map)
    set.insert(i.second);
  return set;
}

bool uniqueOccurrences(vector<int> &arr) {
  const unordered_map<int, int> freq = createMap(arr);
  const unordered_set<int> freqSet = createSet(freq);
  return freq.size() == freqSet.size();
}

int main() {

  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(3);

  return 0;
}
