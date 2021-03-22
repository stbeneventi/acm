/******************************************************************************************************************************
 * ICPC 3004 - Change
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1005
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>

void printMoney(int *moneyLeft, int changeValue, char *changeString) {
  int n = 0;
  while (changeValue <= (*moneyLeft)) {
    (*moneyLeft) -= changeValue;
    n++;
  }
  n > 0 && printf("%s*%d%s", changeString, n, (*moneyLeft) == 0 ? "" : " ");
}

int printChange(int moneyLeft) {
  printMoney(&moneyLeft, 2000, "$20");
  printMoney(&moneyLeft, 1000, "$10");
  printMoney(&moneyLeft, 500, "$5");
  printMoney(&moneyLeft, 200, "$2");
  printMoney(&moneyLeft, 100, "$1");
  printMoney(&moneyLeft, 50, "50c");
  printMoney(&moneyLeft, 20, "20c");
  printMoney(&moneyLeft, 10, "10c");
  printMoney(&moneyLeft, 5, "5c");
  printf("\n");
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
      printf("Not enough money offered.\n");
    else if (diff == 0)
      printf("Exact amount.\n");
    else
      printChange(diff);

    scanf("%d.%d", &d1, &d2);
    cost = d1 * 100 + d2;
    scanf("%d.%d", &d1, &d2);
    offer = d1 * 100 + d2;
  }
  return 0;
}
