#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> splitString(string str) {
  // Used to split string around spaces.
  istringstream ss(str);

  string word; // for storing each word
  vector<string> words;
  // Traverse through all words
  // while loop till we get
  // strings to store in string word
  while (ss >> word) {
    // print the read word
    words.push_back(word);
  }

  return words;
}

vector<string> uncommonFromSentences(string s1, string s2) {
  vector<string> res;
  vector<string> words1 = splitString(s1);
  vector<string> words2 = splitString(s2);

  unordered_map<string, int> map;

  for (auto word : words1)
    map[word]++;

  for (auto word : words2)
    map[word]++;

  for (auto word : map)
    if (word.second == 1)
      res.push_back(word.first);
  return res;
}

int main() {
  string s1 = "this apple is sweet";
  string s2 = "this apple is sour";
  vector<string> res = uncommonFromSentences(s1, s2);
  for (auto s : res) {
    cout << s << "\n";
  }
  return 0;
}
