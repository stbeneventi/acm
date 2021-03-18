/******************************************************************************************************************************
 * 2017 - Hey, You're Not Marion Jones!
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=18
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *readTokenFromStdin(int *length) {
  char delimiter = ' ';

  int indexChars = 0;
  int tokenLength = 8;
  char *token = (char *)malloc(tokenLength * sizeof(char));
  char c = getchar();
  while (c == delimiter) c = getchar();
  while (c != '\n' && c != EOF && c != delimiter) {
    if (indexChars >= tokenLength - 1)
      token = (char *)realloc(token, (tokenLength *= 2) * sizeof(char));
    token[indexChars++] = c;
    c = getchar();
  };
  *length = indexChars;
  token[indexChars] = '\0';
  return token;
}

int mod5(int a) {
  int b = a % 5;
  return (b < 0) * 5 + b;
}

int G[] = {1, 5, 7, 6, 2, 8, 3, 0, 9, 4};

int F(int i, int j) { return i == 0 ? j : F(i - 1, G[j]); }

int ixj(int i, int j) {
  if (i < 5)
    return j < 5 ? mod5((i + j)) : mod5((i + (j - 5))) + 5;
  else
    return j < 5 ? mod5(((i - 5) - j)) + 5 : mod5((i - j));
}

int check(char *id) {
  return !ixj(ixj(ixj(ixj(ixj(ixj(ixj(F(0, id[7] - 48), F(1, id[6] - 48)),
                                  F(2, id[5] - 48)),
                              F(3, id[4] - 48)),
                          F(4, id[3] - 48)),
                      F(5, id[2] - 48)),
                  F(6, id[1] - 48)),
              F(7, id[0] - 48));
}

int number5(char c) { return 90 - c; }

int main() {
  int cases;
  char index;
  int i, j, k, num, length;
  char *barcode;

  scanf("%d\n", &cases);

  for (i = 0; i < cases; i++) {
    char id[] = "00000000";
    int length;
    barcode = readTokenFromStdin(&length);
    num = 0;
    for (j = length - 1, k = 0; j >= 0; j--, k++) {
      num = num + number5(barcode[j]) * pow(5, k);
    }

    if (num > 99999999) {
      printf("%s/%d is invalid id number\n", barcode, num);
      continue;
    }

    int j = 7;
    while (num != 0) {
      id[j] = num % 10 + 48;
      num = num / 10;
      j--;
    }

    if (!check(id)) {
      printf("%s/%s is invalid id number\n", barcode, id);
      continue;
    }

    int typeNum = (id[0] - 48) / 2;

    const char *type[5];
    type[0] = "athlete";
    type[1] = "reserve";
    type[2] = "judge";
    type[3] = "staff";
    type[4] = "press";

    printf("%s/%s is valid %s id number\n", barcode, id, type[typeNum]);
  }
  return 0;
}
