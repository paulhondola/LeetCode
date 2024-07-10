#include <stdbool.h>
#include <string.h>

bool canConstruct(char *ransomNote, char *magazine) {
  int len_note = strlen(ransomNote);
  int len_magazine = strlen(magazine);

  if (len_note > len_magazine) {
    return false;
  }

  int count_note[26] = {0}, count_magazine[26] = {0};

  for (int i = 0; i < len_note; i++) {
    count_note[ransomNote[i] - 'a']++;
  }

  for (int i = 0; i < len_magazine; i++) {
    count_magazine[magazine[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (count_note[i] > count_magazine[i]) {
      return false;
    }
  }

  return true;
}

/*
bool canConstruct(char* ransomNote, char* magazine) {

    //inputs consist of 'a' to 'z' = 97->122 (int)
    int magLen = strlen(magazine);
    int ranLen = strlen(ransomNote);

    if (magLen < ranLen) return false;
    int map[26] = {0};

    for (int i = 0; i < magLen; i++){
        map[magazine[i] - 97]++;
    }

    for (int i =0; i < ranLen; i++){
        //int index = ransomNote[i] - 97;
        map[ransomNote[i] - 97]--;
        if (map[ransomNote[i] - 97]<0){
            return false;
        }
    }
    return true;
}
*/
