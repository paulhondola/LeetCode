#include <string.h>

char *reverseVowels(char *s) {
  const char *vowels = "aeiouAEIOU";
  const int len = strlen(s);

  char vowelsInStr[len];
  int vowelsCount = 0;

  for (int i = 0; i < len; i++)
    if (strchr(vowels, s[i]))
      vowelsInStr[vowelsCount++] = s[i];

  for (int i = 0; i < len; i++)
    if (strchr(vowels, s[i]))
      s[i] = vowelsInStr[--vowelsCount];

  return s;
}

/*
char *reverseVowels(char *s)
{
  char vowels[] = "aeiouAEIOU";

  int l = 0, r = strlen(s) - 1;
  while (l < r)
  {
    bool swapReady = true;
    if (strchr(vowels, s[l]) == NULL)
    {
      l++;
      swapReady = false;
    }
    if (strchr(vowels, s[r]) == NULL)
    {
      r--;
      swapReady = false;
    }

    if (!swapReady)
      continue;

    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    l++;
    r--;
  }

  return s;
}
*/
