/******************************************************************************************************************************
 * ICPC 3004 - Change
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1005
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>

int printChange(int change, int coinValue, char *coin) {
  int n = 0;
  while (coinValue <= change) {
    change -= coinValue;
    n++;
  }
  n > 0 && printf("%s*%d%s", coin, n, change == 0 ? "" : " ");
  return change;
}

int calculateChange(int diff) {
  int left = diff;
  left = printChange(left, 2000, "$20");
  left = printChange(left, 1000, "$10");
  left = printChange(left, 500, "$5");
  left = printChange(left, 200, "$2");
  left = printChange(left, 100, "$1");
  left = printChange(left, 50, "50c");
  left = printChange(left, 20, "20c");
  left = printChange(left, 10, "10c");
  left = printChange(left, 5, "5c");
}

int main(int argc, char **argv) {
  int d1, d2;
  int cost, offer, dec, diff;

  scanf("%d.%d", &d1, &d2);
  cost = d1 * 100 + d2;
  scanf("%d.%d", &d1, &d2);
  offer = d1 * 100 + d2;
  while (cost != 0 && offer != 0) {
    dec = cost % 10;

    cost = cost - dec;

    switch (dec) {
      case 0:
      case 1:
      case 2:
        dec = 0;
        break;
      case 3:
      case 4:
      case 6:
      case 7:
        dec = 5;
        break;
      case 8:
      case 9:
        dec = 10;
        break;
    }

    cost += dec;

    diff = offer - cost;

    if (diff < 0)
      printf("Not enough money offered.");
    else if (diff == 0)
      printf("Exact amount.");
    else
      calculateChange(diff);

    printf("\n");
    scanf("%d.%d", &d1, &d2);
    cost = d1 * 100 + d2;
    scanf("%d.%d", &d1, &d2);
    offer = d1 * 100 + d2;
  }
  return 0;
}
