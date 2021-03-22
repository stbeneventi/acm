/*************************************************************************************************************************
 * 2107 - Double, Double, Toil and Trouble
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=108
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   Este problema es trivial, solo basta con ingresar todas las variables, y
 * ver si T y V, se encuentran dentro de la region definida por los 2 upper
 * bound, y los 2 lower bound.
 *
 */

#include <stdio.h>

int main() {
  int unsafe;

  float flba, flbb, flbc;
  float slba, slbb, slbc;
  float fuba, fubb, fubc;
  float suba, subb, subc;
  float T, V;

  int cases;

  scanf("%d", &cases);

  int i;
  for (i = 0; i < cases; i++) {
    scanf("%f %f %f", &flba, &flbb, &flbc);
    scanf("%f %f %f", &slba, &slbb, &slbc);
    scanf("%f %f %f", &fuba, &fubb, &fubc);
    scanf("%f %f %f", &suba, &subb, &subc);
    scanf("%f %f", &T, &V);

    unsafe = (flbc > flba * T + flbb * V) || (slbc > slba * T + slbb * V) ||
             (fuba * T + fubb * V > fubc) || (suba * T + subb * V > subc);

    printf("%d %sSAFE\n", i + 1, unsafe ? "UN" : "");
  }
}
