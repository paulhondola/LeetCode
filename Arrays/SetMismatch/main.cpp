#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int> &nums) {

  unordered_map<int, int> map;
  vector<int> res(2);
  int n = nums.size();

  for (int i = 0; i < n; i++)
    map[i]++;

  return res;
}
