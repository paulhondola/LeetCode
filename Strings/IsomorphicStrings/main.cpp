#include <string>
#include <unordered_map>

/*
bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        char map_s[128]={0};
        char map_t[128]={0};
        for(int i=0;i<s.length();i++){
            if(map_s[s[i]]!=map_t[t[i]]){
                return false;
            }
            map_s[s[i]]=i+1;
            map_t[t[i]]=i+1;
        }
        return true;
    }
*/

bool isIsomorphic(std::string s, std::string t) {

  std::unordered_map<char, char> s2t;

  for (int i = 0; i < s.size(); i++) {
    if (s2t.find(s[i]) == s2t.end()) {
      s2t[s[i]] = t[i];
    } else {
      if (s2t[s[i]] != t[i]) {
        return false;
      }
    }
  }

  std::unordered_map<char, char> t2s;

  for (int i = 0; i < t.size(); i++) {
    if (t2s.find(t[i]) == t2s.end()) {
      t2s[t[i]] = s[i];
    } else {
      if (t2s[t[i]] != s[i]) {
        return false;
      }
    }
  }

  return true;
}

int main(void) {
  std::string s = "egg";
  std::string t = "add";
  bool result = isIsomorphic(s, t);

  printf("result: %d\n", result); // expect 1 (true)

  return 0;
}
