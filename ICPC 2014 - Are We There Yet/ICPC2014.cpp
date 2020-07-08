/*******************************************************************************
 * 2014 - Are We There Yet?
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=15
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 * Description:
 *   You have a number that represents the location of a cookie, and a kid moves
 * from one position to another, if he gets closer, the program should print
 * "warmer.", if he gets away "colder.", and if doesn't move "same.", and "found
 * it!" if he reach the cookie. There's an extra difficulty, because there's
 * only extra line breaks between the differents outputs but none in the end.
 * The weird thing is that ACM evaluation tool, throws an "Wrong Answer",
 * instead of "Presentation Error".
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitString(string line, char delim = ' ') {
  vector<string> arr;
  stringstream ss(line);
  string token;
  while (std::getline(ss, token, delim)) {
    if (token.length() > 0)

    {
      arr.push_back(token);
    }
  }
  return arr;
}

bool printMove(int cookiePos, int currPos, int nextPos) {
  printf("Moving from %d to %d: ", currPos, nextPos);
  if (cookiePos == nextPos) {
    printf("found it!\n");
    return true;
  } else {
    int diff1 = abs(cookiePos - nextPos);
    int diff2 = abs(cookiePos - currPos);

    if (diff1 < diff2) {
      printf("warmer.\n");
    } else if (diff1 > diff2) {
      printf("colder.\n");
    } else {
      printf("same.\n");
    }
  }
  return false;
}

int main() {
  bool newLineFlag = false;
  string line;
  while (getline(cin, line)) {
    vector<string> array = splitString(line, ' ');
    if (array.size() > 0) {
      int cookiePos = stoi(array.at(0));
      int position = 0;
      if (cookiePos >= 5280 || cookiePos <= -5280) {
        break;
      }
      if (newLineFlag) {
        printf("\n");
      } else {
        newLineFlag = true;
      }
      for (int i = 1; i < array.size(); i++) {
        int nextPosition = stoi(array.at(i));
        if (printMove(cookiePos, position, nextPosition)) {
          break;
        }
        position = nextPosition;
      }
    }
  }
}