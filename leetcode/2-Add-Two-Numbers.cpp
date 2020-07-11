#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* result = new ListNode(-1);
  ListNode* ptr = result;
  int carry = 0;
  while (l1 != nullptr && l2 != nullptr) {
    int add_result = l1->val + l2->val + carry;
    carry = add_result / 10;
    ptr->next = new ListNode(add_result % 10);
    l1 = l1->next;
    l2 = l2->next;
    ptr = ptr->next;
  }
  while (l1 != nullptr) {
    int add_result = l1->val + carry;
    carry = add_result / 10;
    ptr->next = new ListNode(add_result % 10);
    carry = add_result / 10;
    l1 = l1->next;
    ptr = ptr->next;
  }
  while (l2 != nullptr) {
    int add_result = l2->val + carry;
    carry = add_result / 10;
    ptr->next = new ListNode(add_result % 10);
    carry = add_result / 10;
    l2 = l2->next;
    ptr = ptr->next;
  }
  if (carry != 0) {
    ptr->next = new ListNode(carry);
  }
  return result->next;
}

ListNode* create(int arr[], int nums) {
  ListNode* l1 = new ListNode(arr[0]);
  ListNode* ptr = l1;
  for (int i = 1; i < nums; i++) {
    ptr->next = new ListNode(arr[i]);
    ptr = ptr->next;
  }
  return l1;
}

int main() {
  int arr1[] = {2, 4, 3};
  int arr2[] = {5, 6, 4};
  ListNode* l1 = create(arr1, 3);
  ListNode* l2 = create(arr2, 3);
  ListNode* result = addTwoNumbers(l1, l2);
  for (ListNode* ptr = result; ptr != NULL; ptr = ptr->next) {
    cout << ptr->val << " ";
  }
  cout << std::endl;
}