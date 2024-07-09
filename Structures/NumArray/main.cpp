#include <vector>

using namespace std;

class NumArray {

private:
  vector<int> data;

public:
  NumArray(vector<int> &nums) {
    data.resize(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      data[i + 1] = data[i] + nums[i];
    }
  }
  int sumRange(int left, int right) { return data[right + 1] - data[left]; }
};
