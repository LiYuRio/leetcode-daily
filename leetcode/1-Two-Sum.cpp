#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result;
  unordered_map<int, int> table;
  for (int i = 0; i < nums.size(); i++) {
    if (table.find(nums[i]) == table.end()) {
      int remain = target - nums[i];
      table[remain] = i;
    } else {
      result.push_back(table[nums[i]]);
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  int arr[] = {2, 7, 11, 15};
  vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
  int target = 9;
  vector<int> result = twoSum(nums, target);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}