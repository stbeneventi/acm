#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* getToken(char delim, char* index, bool skipDelim) {
  char c = getchar();
  if (c == EOF) {
    *index = EOF;
    return NULL;
  }
  while (skipDelim && c == delim) {
    c = getchar();
    if (c == EOF) {
      *index = EOF;
      return NULL;
    }
  }
  int length = 8;
  char* token = malloc(length * sizeof(char));
  int count = 0;
  while (c != '\n' && c != EOF && c != delim) {
    if (count >= length) {
      token = realloc(token, (length += length) * sizeof(char));
    }
    token[count++] = c;
    c = getchar();
  }
  if (count >= length) {
    token = realloc(token, (length += 1) * sizeof(char));
  }
  token[count] = '\0';
  *index = c;
  return token;
}

void skipLine(char* index) {
  while (*index != '\n' && *index != EOF) {
    *index = getchar();
  }
}

bool printMove(int cookiePos, int currPos, int nextPos) {
  printf("Moving from %d to %d: ", currPos, nextPos);
  if (cookiePos == nextPos) {
    printf("found it!\n");
    return true;
  } else {
    int diff1 = abs(cookiePos - nextPos);
    int diff2 = abs(cookiePos - currPos);

    if (diff1 < diff2) {
      printf("warmer.\n");
    } else if (diff1 > diff2) {
      printf("colder.\n");
    } else {
      printf("same.\n");
    }
  }
  return false;
}

int main() {
  bool newLineFlag = false;
  char index;
  while (index != EOF) {
    int cookiePos = atoi(getToken(' ', &index, true));
    int currPos = 0;
    if (cookiePos >= 5280 || cookiePos <= -5280) {
      break;
    }
    if (newLineFlag) {
      printf("\n");
    } else {
      newLineFlag = true;
    }
    while (index != '\n' && index != EOF) {
      int nextPos = atoi(getToken(' ', &index, true));
      if (printMove(cookiePos, currPos, nextPos)) {
        break;
      };
      currPos = nextPos;
    }
    skipLine(&index);
  }

  return 0;
}