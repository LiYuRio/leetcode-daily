#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
  int states[1000][1000];
  for (int i = 0;i < 1000;i++) {
    for (int j = 0;j < 1000;j++) {
      states[i][j] = 0;
    }
  }
  int max_len = 0;
  string result = "";
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        states[i][j] = 1;
      } else if (s[i] == s[j]) {
        if (i == j - 1) {
          states[i][j] = 2;
        } else if (states[i + 1][j - 1] != 0) {
          states[i][j] = states[i + 1][j - 1] + 2;
        }
      }
      if (states[i][j] > max_len) {
        max_len = states[i][j];
        result = s.substr(i, j - i + 1);
      }
    }
  }
  return result;
}

int main() {
  string s1 = "babad";
  string s2 = "cbbd";
  cout << longestPalindrome(s1) << endl;
  cout << longestPalindrome(s2) << endl;
}