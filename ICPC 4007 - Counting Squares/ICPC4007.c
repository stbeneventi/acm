/******************************************************************************************************************************
 * ICPC 4007 - Counting Squares
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=2008
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>

int main() {
  int px, py, oy, ox;
  int i;
  int sum;
  int cases;
  scanf("%d\n", &cases);
  cases += 1;
  char c;
  for (i = 1; i < cases; i++) {
    px = 0;
    py = 0;
    ox = 0;
    oy = 0;
    sum = 0;
    c = getchar();
    while (c != '\n' && c != EOF) {
      oy = py;
      ox = px;
      if (c == 'U')
        py += 1;
      else if (c == 'D')
        py -= 1;
      else if (c == 'R')
        px += 1;
      else
        px -= 1;
      sum += (ox * (py - oy));
      c = getchar();
    }
    printf("case %d: %d\n", i, sum < 0 ? sum * -1 : sum);
  }
}
