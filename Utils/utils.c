#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char skipInitialDelimiters(char delimiter) {
  char c = getchar();
  while (c == delimiter) c = getchar();
  return c;
}

char *readTokenFromStdin() {
  char delimiter = ' ';
  bool readingToken = false;

  int indexChars = 0;
  int tokenLength = 8;
  char *token = (char *)malloc(tokenLength * sizeof(char));
  char c = skipInitialDelimiters(delimiter);
  while (c != '\n' && c != EOF && c != delimiter) {
    if (indexChars >= tokenLength - 1)
      token = (char *)realloc(token, (tokenLength *= 2) * sizeof(char));
    token[indexChars++] = c;
    c = getchar();
  };
  token[indexChars] = '\0';
  return token;
}

int main() {
  char *s = NULL;
  while ((s = atoi(readTokenFromStdin())) != "") {
    printf("\"%s\"\n", s);
  }
}
