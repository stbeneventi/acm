/******************************************************************************************************************************
 * 2017 - Hey, You're Not Marion Jones!
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=18
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int mod5(int a) {
  if (a == 0 || a % 5 == 0) return 0;
  if (a > 0) return a % 5;
  if (a < 0) return a % 5 + 5;
}

int G(int j) {
  if (j == 0) return 1;
  if (j == 1) return 5;
  if (j == 2) return 7;
  if (j == 3) return 6;
  if (j == 4) return 2;
  if (j == 5) return 8;
  if (j == 6) return 3;
  if (j == 7) return 0;
  if (j == 8) return 9;
  if (j == 9) return 4;
}

int F(int i, int j) {
  if (i == 0) return j;
  if (i == 1) return G(j);
  return F(i - 1, G(j));
}

int ixj(int i, int j) {
  if (i < 5 && j < 5) return mod5((i + j));
  if (i < 5 && j >= 5) return mod5((i + (j - 5))) + 5;
  if (i >= 5 && j < 5) return mod5(((i - 5) - j)) + 5;
  if (i >= 5 && j >= 5) return mod5((i - j));
}

bool check(char* id) {
  int ans = ixj(ixj(ixj(ixj(ixj(ixj(ixj(F(0, id[7] - 48), F(1, id[6] - 48)),
                                    F(2, id[5] - 48)),
                                F(3, id[4] - 48)),
                            F(4, id[3] - 48)),
                        F(5, id[2] - 48)),
                    F(6, id[1] - 48)),
                F(7, id[0] - 48));
  if (ans == 0)
    return true;
  else
    return false;
}

int number5(char c) {
  if (c == 'Z') return 0;
  if (c == 'Y') return 1;
  if (c == 'X') return 2;
  if (c == 'W') return 3;
  if (c == 'V') return 4;
}

int main() {
  int cases;
  char index;
  int i, j, k, num, length;
  char* barcode;

  scanf("%d\n", &cases);

  for (i = 0; i < cases; i++) {
    char id[] = "00000000";
    barcode = getToken(' ', &index, true);
    length = strlen(barcode);
    num = 0;
    for (j = length - 1, k = 0; j >= 0; j--, k++) {
      num = num + number5(barcode[j]) * pow(5, k);
    }

    if (num > 99999999) {
      printf("%s/%d is invalid id number\n", barcode, num);
    } else {
      int j = 7;
      while (num != 0) {
        id[j] = num % 10 + 48;
        num = num / 10;
        j--;
      }

      if (check(id)) {
        if (id[0] == '0' || id[0] == '1')
          printf("%s/%s is valid athlete id number\n", barcode, id);
        else if (id[0] == '2' || id[0] == '3')
          printf("%s/%s is valid reserve id number\n", barcode, id);
        else if (id[0] == '4' || id[0] == '5')
          printf("%s/%s is valid judge id number\n", barcode, id);
        else if (id[0] == '6' || id[0] == '7')
          printf("%s/%s is valid staff id number\n", barcode, id);
        else if (id[0] == '8' || id[0] == '9')
          printf("%s/%s is valid press id number\n", barcode, id);
      } else {
        printf("%s/%s is invalid id number\n", barcode, id);
      }
    }
  }
  return 0;
}
