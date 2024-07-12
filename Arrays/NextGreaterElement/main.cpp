#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> map;

  for (int i = 0; i < nums2.size(); i++) {
    map[nums2[i]] = -1;
  }

  for (int i = 0; i < nums2.size() - 1; i++) {
    for (int j = i + 1; j < nums2.size(); j++) {
      if (nums2[j] > nums2[i]) {
        map[nums2[i]] = nums2[j];
        break;
      }
    }
  }

  vector<int> result;

  for (int i = 0; i < nums1.size(); i++) {
    result.push_back(map[nums1[i]]);
  }

  return result;
}

int main(void) {

  vector<int> nums1;
  vector<int> nums2;

  nums1.push_back(2);
  nums1.push_back(4);

  nums2.push_back(1);
  nums2.push_back(2);
  nums2.push_back(3);
  nums2.push_back(4);

  vector<int> result = nextGreaterElement(nums1, nums2);

  for (auto i : result)
    cout << i << " ";

  return 0;
}
