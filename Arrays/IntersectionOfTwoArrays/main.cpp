#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    for (auto it = set1.begin(); it != set1.end(); it++) {
      if (set2.find(*it) != set2.end()) {
        result.push_back(*it);
      }
    }

    return result;
  }
};
