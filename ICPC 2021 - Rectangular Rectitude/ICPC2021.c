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
  int tmp = *a;
  *a = *b;
  *b = tmp;
};

int canvas[200][200];
int minY = 0;
int minX = 0;
int maxX = 200;
int maxY = 200;

void resetCanvas() {
  int i, j;
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

void setUsedArea(int x1, int y1, int x2, int y2) {
  if (x1 < minX) {
    minX = x1;
  }
  if (y1 < minY) {
    minY = y1;
  }
  if (x2 > maxX) {
    maxX = x2;
  }
  if (y2 > maxY) {
    maxY = y2;
  }
}

void paintCanvas(int c, int x1, int y1, int x2, int y2) {
  if (x1 > x2) {
    swap(&x1, &x2);
  }
  if (y1 > y2) {
    swap(&y1, &y2);
  }

  setUsedArea(x1, y1, x2, y2);

  int i, j;
  for (i = x1; i < x2; i++) {
    for (j = y1; j < y2; j++) {
      canvas[i][j] = c;
    }
  }
}

int getAreaOfColor(int color) {
  int i, j;
  int area = 0;
  for (i = minX; i < maxX; i++) {
    for (j = minY; j < maxY; j++) {
      if (canvas[i][j] == color) area++;
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
      paintCanvas(col, x1, y1, x2, y2);
    }

    printf("The area of color %d in dataset %d is: %d\n", color, dataset,
           getAreaOfColor(color));

    dataset++;

    scanf("%d %d", &nRects, &color);
  }

  return 0;
}
