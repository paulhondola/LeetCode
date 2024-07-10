#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    set<int> s;
    vector<int> missing;

    for (int i = 0; i < nums.size(); i++) {
      s.insert(nums[i]);
    }

    for (int i = 1; i <= nums.size(); i++) {
      if (s.find(i) == s.end()) {
        missing.push_back(i);
      }
    }

    return missing;
  }
};
