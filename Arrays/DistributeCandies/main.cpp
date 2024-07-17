#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int distributeCandies(vector<int> &candyType) {

    unordered_map<int, int> map;

    for (int i = 0; i < candyType.size(); i++) {
      map[candyType[i]]++;
    }

    if (map.size() >= candyType.size() / 2)
      return candyType.size() / 2;

    return map.size();
  }
};

int main(void) {
  vector<int> candyType;

  Solution solution;

  candyType.push_back(1);
  candyType.push_back(1);
  candyType.push_back(2);
  candyType.push_back(2);
  candyType.push_back(3);
  candyType.push_back(3);

  cout << solution.distributeCandies(candyType) << endl;
  return 0;
}
