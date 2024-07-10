#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_multiset<int> s(nums1.begin(), nums1.end());

    for (int num : nums2) {
      auto pos = s.find(num);
      if (pos != s.end()) {
        result.push_back(num);
        s.erase(pos);
      }
    }

    return result;
  }
};

/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};
*/
