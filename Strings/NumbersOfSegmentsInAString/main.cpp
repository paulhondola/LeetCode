
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  int countSegments(string s) {
    string sentence = s;
    stringstream ss(sentence); // Create a stringstream object

    int count = 0;
    string word;
    while (ss >> word) {
      count++;
    }

    return count;
  }
};

int main() {
  std::string sentence = "Hello, how are you?";
  std::stringstream ss(sentence); // Create a stringstream object

  std::string word;

  while (ss >> word) {              // Extracts each word from the stringstream
    std::cout << word << std::endl; // Print each word separately
  }

  return 0;
}
