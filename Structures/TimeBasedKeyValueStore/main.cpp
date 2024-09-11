#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TimeMap {
  unordered_map<string, vector<pair<string, int>>> map;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    pair<string, int> p = make_pair(value, timestamp);
    map[key].push_back(p);
  }

  string get(string key, int timestamp) {
    string res;
    if (map.find(key) == map.end())
      return res;

    int left = 0, right = map[key].size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      // if the timestamp is greater than the current timestamp
      // then we need to move to the right

      if (map[key][mid].second <= timestamp) {
        res = map[key][mid].first;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return res;
  }
};

int main() { return 0; }
