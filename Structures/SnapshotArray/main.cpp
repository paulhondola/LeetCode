#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class SnapshotArray {
  vector<vector<int>> array;
  int snap_id;
  int length;

public:
  SnapshotArray(int length) {
    this->length = length;
    snap_id = 0;
    initNewSnap(length);
  }

  void initNewSnap(const int length) {
    array[snap_id].resize(length);
    for (int i = 0; i < length; i++)
      array[snap_id][i] = 0;
  }

  void set(int index, int val) { array[snap_id][index] = val; }

  int snap() {
    snap_id++;
    initNewSnap(length);
    return snap_id - 1;
  }

  int get(int index, int snap_id) { return array[snap_id][index]; }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main() { return 0; }
