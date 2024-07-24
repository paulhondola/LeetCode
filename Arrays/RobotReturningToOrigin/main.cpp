#include <stack>
#include <string>
using namespace std;

bool judgeCircle(string moves) {
  stack<char> horizontal, vertical;

  for (auto i : moves) {
    switch (i) {
    case 'U':
      if (!vertical.empty() && vertical.top() == 'D')
        vertical.pop();
      else
        vertical.push(i);
      break;

    case 'D':
      if (!vertical.empty() && vertical.top() == 'U')
        vertical.pop();
      else
        vertical.push(i);
      break;

    case 'L':
      if (!horizontal.empty() && horizontal.top() == 'R')
        horizontal.pop();
      else
        horizontal.push(i);
      break;

    case 'R':
      if (!horizontal.empty() && horizontal.top() == 'L')
        horizontal.pop();
      else
        horizontal.push(i);
      break;
    }
  }

  return horizontal.empty() && vertical.empty();
}
