string removeDuplicates(string s) {
  string res;

  for (auto c : s) {
    if (res.empty() || res.back() != c) {
      res.push_back(c);
    } else {
      res.pop_back();
    }
  }

  return res;
}
