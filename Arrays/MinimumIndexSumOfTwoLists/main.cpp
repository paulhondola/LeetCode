#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {

  unordered_map<string, int> map;

  for (int i = 0; i < list1.size(); i++)
    map[list1[i]] = i;

  for (int i = 0; i < list2.size(); i++)
    if (map.find(list2[i]) != map.end())
      map[list2[i]] += i;
    else
      map[list2[i]] = INT_MAX;

  vector<string> res;

  int min = INT_MAX;

  for (auto it = map.begin(); it != map.end(); it++) {
    if (it->second < min) {
      res.clear();
      res.push_back(it->first);
      min = it->second;
    } else if (it->second == min) {
      res.push_back(it->first);
    }
  }

  return res;
}
