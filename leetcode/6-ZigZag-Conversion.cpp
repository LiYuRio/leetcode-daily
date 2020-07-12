#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows) {
  if (numRows == 1) {
    return s;
  }
  string result = "";
  int n = s.size();
  for (int i = 0; i < numRows; i++) {
    int j = i;
    while (j < n) {
      result += s[j];
      if (i != 0 && (i != numRows - 1)) {
        int k = j + (numRows - i - 1) * 2;
        if (k < n) {
          result += s[k];
        }
      }
      j = j + (numRows - 1) * 2;
    }
  }
  return result;
}
int main() {
  string s = "PAYPALISHIRING";
  cout << convert(s, 3) << endl;
  cout << convert(s, 4) << endl;
}