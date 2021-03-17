/*******************************************************************************
 * 2014 - Are We There Yet?
 *
 * Url:
 *   https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=15
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Notes:
 *   The difficulty of this problem is the variable number of integers of the
 * input because the scanf function ignores newline characters, so the solution
 * is to use a reader that allows to read newline characters.
 * Note that there's two linebreaks between every case, but there's only one
 * after the final case. If that's incorrect, the evaluation tool throws a
 * "Wrong Answer", instead of a "Presentation Error".
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char skipInitialDelimiters(delimiter) {
  char c = getchar();
  while (c == delimiter) c = getchar();
  return c;
}

char *readTokenFromStdin(bool *linebreak) {
  char delimiter = ' ';

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
  linebreak = (c == '\n');
  return token;
}

bool move(int cookiePos, int currPos, int nextPos) {
  printf("Moving from %d to %d: ", currPos, nextPos);
  if (cookiePos == nextPos) {
    printf("found it!\n");
    return false;
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
  return true;
}

int main() {
  bool firstCase = true;
  bool linebreak = false;
  int cookiePosition = atoi(readTokenFromStdin(&linebreak));
  while (cookiePosition < abs(5280)) {
    if (!firstCase) printf("\n");
    int currentPosition = 0;
    int nextPosition = atoi(readTokenFromStdin(&linebreak));
    while (!linebreak) {
      if (!move(cookiePosition, currentPosition, nextPosition)) break;
      currentPosition = nextPosition;
      nextPosition = atoi(readTokenFromStdin(&linebreak));
    }
    cookiePosition = atoi(readTokenFromStdin(&linebreak));
    firstCase = false;
  }

  return 0;
}
