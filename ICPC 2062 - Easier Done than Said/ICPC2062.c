/*************************************************************************************************************************
 * 2062 - Easier Done than Said?
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=63
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

int vowel[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int isVowel(char c) { return vowel[c - 97]; }

char tmp = 'x';
int twoConsecutiveLetters(char c) { return (c == tmp) && c != 'e' && c != 'o'; }

int tmp2[2] = {0, 0};
int threeConsecutiveType(char c) {
  int vowel = isVowel(c);
  return (vowel == tmp2[0]) && (vowel == tmp2[1]);
}

char *readTokenAndValidate(int *isValid) {
  int indexChars = 0;
  int tokenLength = 8;
  char *token = (char *)malloc(tokenLength * sizeof(char));
  char c = getchar();

  int notFoundVowel = 1;
  *isValid = 1;
  while (c != '\n' && c != EOF) {
    if (indexChars >= tokenLength - 1)
      token = (char *)realloc(token, (tokenLength *= 2) * sizeof(char));
    token[indexChars++] = c;
    if (*isValid) {
      notFoundVowel && (isVowel(c)) && (notFoundVowel = 0);
      indexChars > 1 && twoConsecutiveLetters(c) && (*isValid = 0);
      indexChars > 2 && threeConsecutiveType(c) && (*isValid = 0);
      tmp = c;
      tmp2[indexChars & 1] = isVowel(c);
    }
    c = getchar();
  };
  *isValid = !notFoundVowel && *isValid;
  token[indexChars] = '\0';
  return token;
}

int isNotEnd(char *p) {
  return p[0] != 'e' || p[1] != 'n' || p[2] != 'd' || p[3] != '\0';
}

int main() {
  int isValid = 1;
  char *password = readTokenAndValidate(&isValid);
  while (isNotEnd(password)) {
    printf("<%s> is%s acceptable.\n", password, isValid ? "" : " not");
    password = readTokenAndValidate(&isValid);
  }
  return 0;
}
