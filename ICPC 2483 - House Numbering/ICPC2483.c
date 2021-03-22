/******************************************************************************************************************************
 * ICPC 2483 - House Numbering
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=484
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b;
  int set = 1;
  int number, price;
  char c = getchar();
  while (c != '#') {
    printf("Set %d\n", set);
    while (c != ' ') c = getchar();
    scanf("%d %d\n", &a, &b);
    while (c != '#' && c != 'C') {
      scanf("%d\n", &number);
      price = 0;
      number = number << 1;
      while (number = number >> 1) price = price + (number & 1 ? b : a);
      printf("%d\n", price);
      c = getchar();
      ungetc(c, stdin);
    }
    set++;
  }
}
