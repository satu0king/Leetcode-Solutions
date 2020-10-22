/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> s1;
    stack<int> s2;

    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }

    int carry = 0;

    ListNode *prev = NULL;

    while (s1.size() || s2.size() || carry) {
      int s = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + carry;

      if (s1.size())
        s1.pop();
      if (s2.size())
        s2.pop();

      carry = s > 9;
      ListNode *temp = new ListNode(s % 10);
      temp->next = prev;
      prev = temp;
    }

    return prev;
  }
};
