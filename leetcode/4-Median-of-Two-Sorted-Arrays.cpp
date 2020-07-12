#include <iostream>
#include <vector>
using namespace std;

double iteration_solution(vector<int>& nums1, int s1, int e1,
                          vector<int>& nums2, int s2, int e2, int k) {
  if (e2 - s2 == 0) {
    return nums1[s1 + k - 1];
  }
  if (e1 - s1 == 0) {
    return nums2[s2 + k - 1];
  }
  if (k == 1) {
    if (nums1[s1] < nums2[s2]) {
      return nums1[s1];
    }
    return nums2[s2];
  }
  int i1 = k / 2 - 1;
  int i2 = k / 2 - 1;
  if (i1 + s1 >= e1) {
    i1 = e1 - 1;
  }
  if (i2 + s2 >= e2) {
    i2 = e2 - 1;
  }
  if (nums1[i1 + s1] < nums2[i2 + s2]) {
    return iteration_solution(nums1, s1 + i1 + 1, e1, nums2, s2, e2,
                              k - i1 - 1);
  } else {
    return iteration_solution(nums1, s1, e1, nums2, s2 + i2 + 1, e2,
                              k - i2 - 1);
  }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int m = nums1.size();
  int n = nums2.size();
  if ((m + n) % 2 == 0) {
    int a = iteration_solution(nums1, 0, m, nums2, 0, n, (m + n) / 2);
    int b = iteration_solution(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
    return (a + b) / 2.0;
  } else {
    return iteration_solution(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
  }
}

int main() {
  int arr1[] = {1, 3};
  int arr2[] = {2};
  vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
  vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
  cout << findMedianSortedArrays(nums1, nums2) << endl;
}