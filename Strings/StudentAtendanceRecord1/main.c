bool checkRecord(char *s) {
  // The student was absent ('A') for strictly fewer than 2 days total.
  // The student was never late ('L') for 3 or more consecutive days.

  if (strstr(s, "LLL"))
    return false;

  int index = strchr(s, 'A') - s;

  if (index >= 0 && index < strlen(s) - 1) {
    if (strchr(s + index + 1, 'A'))
      return false;
  }

  return true;
}
