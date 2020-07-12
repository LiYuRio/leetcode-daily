#include <iostream>
using namespace std;

int reverse(int x) {
  int result = 0;
  while (x != 0) {
    if (result > INT_MAX / 10 || result < INT_MIN / 10) {
      return 0;
    }
    result = result * 10 + (x % 10);
    x = x / 10;
  }
  return result;
}

int main() {
  int x1 = 321;
  int x2 = -321;
  int x3 = INT_MIN;
  int x4 = INT_MAX;
  cout << reverse(x1) << endl;
  cout << reverse(x2) << endl;
  cout << reverse(x3) << endl;
  cout << reverse(x4) << endl;
}