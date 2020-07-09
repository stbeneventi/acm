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

char* getToken(char delim, char* index, bool skipDelim) {
  char c = getchar();
  if (c == EOF) {
    *index = EOF;
    return NULL;
  }
  while (skipDelim && c == delim) {
    c = getchar();
    if (c == EOF) {
      *index = EOF;
      return NULL;
    }
  }
  int length = 8;
  char* token = malloc(length * sizeof(char));
  int count = 0;
  while (c != '\n' && c != EOF && c != delim) {
    if (count >= length) {
      token = realloc(token, (length += length) * sizeof(char));
    }
    token[count++] = c;
    c = getchar();
  }
  if (count >= length) {
    token = realloc(token, (length += 1) * sizeof(char));
  }
  token[count] = '\0';
  *index = c;
  return token;
}

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
  for (i = 0; i < 200; i++) {
    for (j = 0; j < 200; j++) {
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
  char index;
  int nRects, color;
  int col, x1, x2, y1, y2;
  int dataset = 1;

  nRects = atoi(getToken(' ', &index, true));
  color = atoi(getToken(' ', &index, true));

  while (nRects != 0) {
    resetCanvas();
    int i;
    for (i = 0; i < nRects; i++) {
      col = atoi(getToken(' ', &index, true));
      x1 = atoi(getToken(' ', &index, true)) + 100;
      y1 = atoi(getToken(' ', &index, true)) + 100;
      x2 = atoi(getToken(' ', &index, true)) + 100;
      y2 = atoi(getToken(' ', &index, true)) + 100;
      paintCanvas(col, x1, y1, x2, y2);
    }

    printf("The area of color %d in dataset %d is: %d\n", color, dataset,
           getAreaOfColor(color));

    dataset++;

    nRects = atoi(getToken(' ', &index, true));
    color = atoi(getToken(' ', &index, true));
  }

  return 0;
}
