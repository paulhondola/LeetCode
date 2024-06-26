#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expandAroundCenter(const char *s, int left, int right, int *start, int *maxLength) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    int len = right - left - 1;
    if (len > *maxLength) {
        *start = left + 1;
        *maxLength = len;
    }
}

char* longestPalindrome(const char *s) {
    int start = 0, maxLength = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        expandAroundCenter(s, i, i, &start, &maxLength);      // Odd length palindromes
        expandAroundCenter(s, i, i + 1, &start, &maxLength);  // Even length palindromes
    }

    char *result = (char *)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    return result;
}

int main() {
    char s[] = "aaaaabbaaaaaaaa";
    char *result = longestPalindrome(s);
    printf("Longest Palindromic Substring: %s\n", result);
    free(result);
    return 0;
}
