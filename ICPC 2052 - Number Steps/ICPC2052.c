/******************************************************************************************************************************
 * 2052 - Number Steps
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=53
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>

int main() {
  int x, y, cases;
  int resp;
  scanf("%d", &cases);
  int i;
  for (i = 0; i < cases; i++) {
    scanf("%d %d", &x, &y);
    if (x == y || x == y + 2) {
      if (x % 2 == 0)
        resp = x + y;
      else
        resp = x + y - 1;
      printf("%d\n", resp);
    } else
      printf("No Number\n");
  }
}
