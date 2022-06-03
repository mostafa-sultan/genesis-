// test caes
// 6
// 1 5
// 1 20
// 1 50
// 2 5
// 2 20
// 2 50
// 6
// 1 5
// 1 80
// 1 50
// 2 5
// 2 80
// 2 50
// 6
// 1 1
// 1 5
// 1 10
// 2 10
// 2 5
// 2 1
// 4
// 1 100
// 1 50
// 2 50
// 2 100
// 2
// 1 20
// 2 100

#include <iostream>

#include <fstream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <stack>

#include <queue>

using namespace std;

int main() {
  int num;
  while (scanf("%d", & num) != EOF) {
    int isStack = 1, isqueue = 1, priority = 1;
    stack < int > stack;
    queue < int > queue;
    priority_queue < int > prqueue;
    int a, b;
    while (num--) {
      scanf("%d %d", & a, & b);
      if (a == 1) {
        stack.push(b);
        queue.push(b);
        prqueue.push(b);
      } else {
        if (!stack.empty() && stack.top() == b) stack.pop();
        else isStack = 0;
        if (!queue.empty() && queue.front() == b) queue.pop();
        else isqueue = 0;
        if (!prqueue.empty() && prqueue.top() == b) prqueue.pop();
        else priority = 0;
      }
    }
    ofstream txtFile("result.txt");

    if (isStack + isqueue + priority >= 2) {
      printf("?\n");
      txtFile << "?\n";
    } else if (isStack == 1) {
      printf("s\n");
      txtFile << "s\n";
    } else if (isqueue == 1) {
      printf("q\n");
      txtFile << "q\n";
    } else if (priority == 1) {
      printf("q\n");
      txtFile << "q\n";
    } else if (isStack == 0 && isqueue == 0 && priority == 0) {
      printf("!\n");
      txtFile << "!\n";
    }
    txtFile.close();
  }

  return 0;
}