#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> splitString(string &input, char delimiter) {

    // Creating an input string stream from the input string
    istringstream stream(input);

    // Vector to store the tokens
    vector<string> tokens;

    // Temporary string to store each token
    string token;

    // Read tokens from the string stream separated by the
    // delimiter
    while (getline(stream, token, delimiter)) {
      // Add the token to the vector of tokens
      tokens.push_back(token);
    }

    // Return the vector of tokens
    return tokens;
  }

  bool wordPattern(string pattern, string s) {
    map<char, string> p2s;

    vector<string> words;

    words = splitString(s, ' ');

    if (pattern.size() != words.size()) {
      return false;
    }

    for (int i = 0; i < pattern.size(); i++) {
      if (p2s.find(pattern[i]) == p2s.end()) {
        p2s[pattern[i]] = words[i];
      } else {
        if (p2s[pattern[i]] != words[i]) {
          return false;
        }
      }
    }

    // check for duplicate values in the map

    map<string, char> s2p;

    for (int i = 0; i < words.size(); i++) {
      if (s2p.find(words[i]) == s2p.end()) {
        s2p[words[i]] = pattern[i];
      } else {
        if (s2p[words[i]] != pattern[i]) {
          return false;
        }
      }
    }

    return true;
  }
};
