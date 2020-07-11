#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int start = 0;
  int last = 0;
  int n = s.size();
  unordered_map<char, int> table;
  int max_len = 0;
  while (last < n) {
    if (table.find(s[last]) == table.end() || table[s[last]] < start) {
      table[s[last]] = last;
      if (last - start + 1 > max_len) {
        max_len = last - start + 1;
      }
    } else {
      start = table[s[last]] + 1;
      table[s[last]] = last;
    }
    last++;
  }
  return max_len;
}

int main() {
  string s1 = "";
  cout << s1 << ": " << lengthOfLongestSubstring(s1) << endl;
  string s2 = "abcabcbb";
  cout << s2 << ": " << lengthOfLongestSubstring(s2) << endl;
  string s3 = "bbbbb";
  cout << s3 << ": " << lengthOfLongestSubstring(s3) << endl;
  string s4 = "pwwkew";
  cout << s4 << ": " << lengthOfLongestSubstring(s4) << endl;
  string s5 = "bbbbba";
  cout << s5 << ": " << lengthOfLongestSubstring(s5) << endl;
  string s6 = "tmmzuxt";
  cout << s6 << ": " << lengthOfLongestSubstring(s6) << endl;
}