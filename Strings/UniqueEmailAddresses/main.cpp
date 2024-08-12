#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string editEmail(string mail) {
  string editedMail = "";

  for (auto i = 0; i < mail.size(); i++) {
    if (mail[i] == '.')
      continue;

    if (mail[i] == '+') {
      while (mail[i] != '@')
        i++;
    }

    if (mail[i] == '@') {
      editedMail += mail.substr(i, mail.size());
      break;
    }

    editedMail += mail[i];
  }

  return editedMail;
}

int numUniqueEmails(vector<string> &emails) {
  unordered_set<string> set;

  for (auto i : emails) {
    cout << editEmail(i) << endl;
    set.insert(editEmail(i));
  }

  return set.size();
}

int main(void) {
  vector<string> emails(3);

  emails.push_back("test.email+alex@leetcode.com");
  emails.push_back("test.e.mail+bob.cathy@leetcode.com");
  emails.push_back("testemail+david@lee.tcode.com");

  cout << numUniqueEmails(emails) << endl;

  return 0;
}
