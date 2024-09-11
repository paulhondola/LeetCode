#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void sortDomino(vector<int> &domino) {
  if (domino[0] > domino[1]) {
    int temp = domino[0];
    domino[0] = domino[1];
    domino[1] = temp;
  }
}

int numEquivDominoPairs(vector<vector<int>> &dominoes) {
  unordered_map<string, int> map;
  int count = 0;
  for (int i = 0; i < dominoes.size(); i++) {
    sortDomino(dominoes[i]);
    string key = to_string(dominoes[i][0]) + to_string(dominoes[i][1]);
    if (map.find(key) != map.end()) {
      count += map[key];
      map[key]++;
    } else {
      map[key] = 1;
    }
  }
  return count;
}

int main() {

  vector<vector<int>> dominoes;
  vector<int> domino1;
  vector<int> domino2;
  vector<int> domino3;
  vector<int> domino4;

  domino1.push_back(1);
  domino1.push_back(2);

  domino2.push_back(2);
  domino2.push_back(1);

  domino3.push_back(3);
  domino3.push_back(4);

  domino4.push_back(5);
  domino4.push_back(6);

  dominoes.push_back(domino1);
  dominoes.push_back(domino2);
  dominoes.push_back(domino3);
  dominoes.push_back(domino4);

  cout << numEquivDominoPairs(dominoes) << endl;

  return 0;
}
