#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findShortestSubArray(vector<int> &nums) {
  unordered_map<int, int> count, first, last;
  int degree = 0;

  // Populate the maps and calculate the degree
  for (int i = 0; i < nums.size(); ++i) {
    int num = nums[i];
    count[num]++;
    if (first.find(num) == first.end()) {
      first[num] = i;
    }
    last[num] = i;
    degree = max(degree, count[num]);
  }

  int minLength = INT_MAX;

  // Find the shortest subarray with the same degree
  for (const auto &entry : count) {
    if (entry.second == degree) {
      int num = entry.first;
      int length = last[num] - first[num] + 1;
      minLength = min(minLength, length);
    }
  }

  return minLength;
}

int main() {
  vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
  cout << "Shortest subarray length with the same degree: "
       << findShortestSubArray(nums) << endl;

  return 0;
}
