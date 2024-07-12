#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score) {
  map<int, int> scoreMap;
  vector<string> result;

  switch (score.size()) {
  case 0:
    return result;
    break;
  case 1:
    result.push_back("Gold Medal");
    return result;
    break;

  case 2:
    if (score[0] > score[1]) {
      result.push_back("Gold Medal");
      result.push_back("Silver Medal");
      return result;
    } else {
      result.push_back("Silver Medal");
      result.push_back("Gold Medal");
      return result;
    }
    break;
  default:
    break;
  }

  result = vector<string>(score.size(), "");

  for (int i = 0; i < score.size(); i++)
    scoreMap[score[i]] = i;

  for (auto i : scoreMap) {
    cout << i.first << " " << i.second << endl;
  }

  map<int, int>::reverse_iterator it = scoreMap.rbegin();

  for (int i = 0; i < 3; i++) {
    switch (i) {
    case 0:
      result[it->second] = "Gold Medal";
      break;
    case 1:
      result[it->second] = "Silver Medal";
      break;
    case 2:
      result[it->second] = "Bronze Medal";
      break;
    }

    it++;
  }

  int count = 4;
  for (int i = 3; i < score.size(); i++) {
    result[it->second] = to_string(count);
    count++;
    it++;
  }

  return result;
}

int main(void) {
  vector<int> score;
  score.push_back(10);
  score.push_back(3);
  score.push_back(8);
  score.push_back(9);
  score.push_back(4);

  vector<string> result = findRelativeRanks(score);

  for (auto i : result)
    cout << i << " ";

  return 0;
}

/*
class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
    int n = score.size();
    std::vector<std::pair<int, int>> scoreIndexPairs;

    // Step 1: Create a vector of pairs (score, index)
    for (int i = 0; i < n; ++i) {
        scoreIndexPairs.push_back({score[i], i});
    }

    // Step 2: Sort the pairs in descending order by score
    std::sort(scoreIndexPairs.begin(), scoreIndexPairs.end(),
std::greater<std::pair<int, int>>());

    // Step 3: Assign ranks based on sorted positions
    std::vector<std::string> result(n);
    for (int i = 0; i < n; ++i) {
        int index = scoreIndexPairs[i].second;
        if (i == 0) {
            result[index] = "Gold Medal";
        } else if (i == 1) {
            result[index] = "Silver Medal";
        } else if (i == 2) {
            result[index] = "Bronze Medal";
        } else {
            result[index] = std::to_string(i + 1);
        }
    }

    return result;
}
};
*/
