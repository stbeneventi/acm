/******************************************************************************************************************************
 * 2202 - Vito's Family
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=203
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main() {
  int cases, relativesNum, i = 0, j = 0, streetNum, optimal, sum;
  scanf("%d", &cases);
  int array[1000];
  for (i = 0; i < cases; i++) {
    scanf("%d", &relativesNum);
    for (j = 0; j < relativesNum; j++) {
      scanf("%d", &streetNum);
      array[j] = streetNum;
    }
    qsort(array, relativesNum, sizeof(int), cmpfunc);
    optimal = array[(relativesNum - (relativesNum & 1)) / 2];
    sum = 0;
    for (j = 0; j < relativesNum; j++) sum = sum + abs(optimal - array[j]);
    printf("%d\n", sum);
  }
}
