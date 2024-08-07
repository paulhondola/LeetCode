#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to split the string by multiple delimiters
vector<string> splitStringByDelimiters(const string &str) {
  vector<string> tokens;
  string token;

  for (char c : str) {
    if (ispunct(c) || isspace(c)) {
      if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
      }
    } else {
      token += tolower(c); // Convert to lowercase
    }
  }

  if (!token.empty()) {
    tokens.push_back(token);
  }

  return tokens;
}

string mostCommonWord(string paragraph, vector<string> &banned) {

  unordered_set<string> bannedSet(banned.begin(), banned.end());
  unordered_map<string, int> wordCount;

  vector<string> words = splitStringByDelimiters(paragraph);

  // Count the frequency of each word, ignoring banned words
  for (const string &word : words) {
    if (bannedSet.find(word) == bannedSet.end()) {
      wordCount[word]++;
    }
  }

  // Find the word with the highest frequency
  string mostCommon;
  int maxCount = 0;
  for (const auto &entry : wordCount) {
    if (entry.second > maxCount) {
      mostCommon = entry.first;
      maxCount = entry.second;
    }
  }

  return mostCommon;
}

int main() {
  string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  vector<string> banned = {"hit"};

  vector<string> words = splitStringByDelimiters(paragraph);

  string result = mostCommonWord(paragraph, banned);
  cout << "Most common word: " << result << endl; // Output: "ball"

  return 0;
}
