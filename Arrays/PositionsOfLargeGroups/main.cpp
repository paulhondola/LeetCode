#include <string>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string s) {

  // s = abbxxxxzzy -> group of more than 3 consecutive characters

  int n = s.length();
  int count = 1;
  bool first_flag_set = false;

  int start = 0;
  int end = 0;
  vector<vector<int>> result;

  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      count++;

      if (!first_flag_set) {
        first_flag_set = true;
        start = i - 1;
      }

      if (count >= 3)
        end = i;
    } else {
      if (count >= 3) {
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        result.push_back(temp);
      }

      first_flag_set = false;
      count = 1;
    }
  }

  if (count >= 3) {
    vector<int> temp;
    temp.push_back(start);
    temp.push_back(end);
    result.push_back(temp);
  }

  return result;
}
