/******************************************************************************************************************************
 * ICPC 3045 - Gold Coins
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1046
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <math.h>
#include <stdio.h>

int payDayN[10000];
int nextInit = 0;
int gold = 1;
int counter = 0;

int initializeGold(int day) {
  int i;
  for (i = nextInit; i < day; i++) {
    payDayN[i] = gold;
    counter++;
    if (counter == gold) {
      gold++;
      counter = 0;
    }
  }
  if (day > nextInit) nextInit = day;
}

int accGoldDayN(int day) {
  int i, acc = 0;
  for (i = 0; i < day; i++) acc += payDayN[i];
  return acc;
}

int main(int argc, char **argv) {
  int day;
  scanf("%d", &day);
  while (day != 0) {
    initializeGold(day);
    printf("%d %d\n", day, accGoldDayN(day));
    scanf("%d", &day);
  }

  return 0;
}
