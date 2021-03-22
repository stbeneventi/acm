/*************************************************************************************************************************
 * 3600 - Root of the Problem
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=1601
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int B, N;
  int d1, d2;
  float root;
  double exp;
  int ans;
  float diff;

  scanf("%d %d ", &B, &N);
  while (B != 0 || N != 0) {
    exp = (double)1 / N;
    root = pow(B, exp);
    ans = (int)root;
    d1 = (int)pow(ans, N);
    d2 = (int)pow(ans + 1, N);
    printf("%d\n", ans + !(abs(B - d1) < abs(B - d2)));
    scanf("%d %d ", &B, &N);
  }
}
