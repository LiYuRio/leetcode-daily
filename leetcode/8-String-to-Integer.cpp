#include <iostream>
#include <string>
using namespace std;
int myAtoi(string str) {
  int n = str.size();
  int i = 0;
  long result = 0;
  for (; i < n; i++) {
    if (str[i] != ' ') {
      break;
    }
  }
  int sign = 1;
  if (str[i] == '+') {
    i++;
  } else if (str[i] == '-') {
    sign = -1;
    i++;
  }
  for (; i < n; i++) {
    if (!isdigit(str[i])) {
      return result;
    }
    result = result * 10 + (str[i] - '0') * sign;
    if (result > INT_MAX) {
      return INT_MAX;
    } else if (result < INT_MIN) {
      return INT_MIN;
    }
  }
  return result;
}
int main() {
  string s1 = "42";
  string s2 = "-42";
  string s3 = "4193 with words";
  string s4 = "words and 987";
  string s5 = "-91283472332";
  cout << myAtoi(s1) << endl;
  cout << myAtoi(s2) << endl;
  cout << myAtoi(s3) << endl;
  cout << myAtoi(s4) << endl;
  cout << myAtoi(s5) << endl;
}