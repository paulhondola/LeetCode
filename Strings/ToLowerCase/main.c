char *toLowerCase(char *s) {
  int left = 0, right = strlen(s) - 1;

  while (left < right) {
    if (s[left] >= 'A' && s[left] <= 'Z') {
      s[left] = s[left] + 32;
    }

    if (s[right] >= 'A' && s[right] <= 'Z') {
      s[right] = s[right] + 32;
    }

    left++;
    right--;
  }

  return s;
}
