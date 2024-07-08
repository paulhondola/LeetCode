#include <map>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {

    map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
        return true;
      }
      map[nums[i]] = i;
    }

    return false;
  }
};

// Maintain a set of size k+1. If the size exceeds k, remove the oldest element.
/*
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::unordered_set<int> usi;
        for(int i=0; i<nums.size(); ++i)
        {
            if(usi.count(nums[i]))
            {
                return true;
            }
            usi.insert(nums[i]);
            if(usi.size()>k)
            {
                usi.erase(nums[i-k]);
            }
        }
        return false;
    }
};
*/
