/******************************************************************************************************************************
 * ICPC 2021 - Rectangular Rectitude
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=22
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int canvas[200][200];
int minY = 200;
int minX = 200;
int maxX = 0;
int maxY = 0;

void resetCanvas() {
  int i, j;
  if (minX > maxX) return;
  for (i = minX; i < maxX; i++) {
    for (j = minY; j < maxY; j++) {
      canvas[i][j] = 0;
    }
  }
  minY = 200;
  minX = 200;
  maxX = 0;
  maxY = 0;
}

void paint(int x1, int y1, int x2, int y2) {
  if (x1 < minX) minX = x1;
  if (y1 < minY) minY = y1;
  if (x2 > maxX) maxX = x2;
  if (y2 > maxY) maxY = y2;
  int i, j;
  for (i = x1; i < x2; i++) {
    for (j = y1; j < y2; j++) {
      canvas[i][j] = 1;
    }
  }
}

void removePaint(int x1, int y1, int x2, int y2) {
  if (x1 < minX) x1 = minX;
  if (y1 < minY) y1 = minY;
  if (x2 > maxX) x2 = maxX;
  if (y2 > maxY) y2 = maxY;
  int flag = ((x1 == minX) && 1) | ((y1 == minY) && 2) | ((x2 == maxX) && 4) |
             ((y2 == maxY) && 8);
  int i, j;
  for (i = x1; i < x2; i++) {
    for (j = y1; j < y2; j++) {
      canvas[i][j] = 0;
    }
  }
  switch (flag) {
    case 15:
      minY = 200;
      minX = 200;
      maxX = 0;
      maxY = 0;
      break;
    case 7: /* x1 == minX && x2 == maxX && y1 == minY */
      if (y2 < maxY) minY = y2;
      break;
    case 13: /* x1 == minX && x2 == maxX && y2 == maxY */
      if (y1 > minY) maxY = y1;
      break;
    case 11: /* y1 == minY && y2 == maxY && x1 == minX */
      if (x2 < maxX) minX = x2;
    case 14: /* y1 == minY && y2 == maxY && x2 == maxX */
      if (x1 > minX) maxY = x1;
    default:
      break;
  }
}

int getAreaOfColor(int color) {
  int i, j;
  int area = 0;
  for (i = minX; i < maxX; i++) {
    for (j = minY; j < maxY; j++) {
      if (canvas[i][j]) area++;
    }
  }
  return area;
}

int main() {
  int nRects, color;
  int col, x1, x2, y1, y2;
  int dataset = 1;

  scanf("%d %d", &nRects, &color);
  while (nRects != 0) {
    resetCanvas();
    int i;
    for (i = 0; i < nRects; i++) {
      scanf("%d %d %d %d %d", &col, &x1, &y1, &x2, &y2);
      x1 += 100;
      y1 += 100;
      x2 += 100;
      y2 += 100;
      if (x1 > x2) swap(&x1, &x2);
      if (y1 > y2) swap(&y1, &y2);
      color == col ? paint(x1, y1, x2, y2) : removePaint(x1, y1, x2, y2);
    }

    printf("The area of color %d in dataset %d is: %d\n", color, dataset,
           getAreaOfColor(color));

    dataset++;
    scanf("%d %d", &nRects, &color);
  }

  return 0;
}
