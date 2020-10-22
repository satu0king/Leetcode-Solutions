/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == NULL)
      return NULL;
    if (head->next == NULL)
      return head;
    // cout << head->val << endl;
    ListNode *temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
  }
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *start, *end, *startprev = NULL;
    int pos = 1;
    ListNode *temp = head;
    while (temp != NULL) {
      if (pos == m - 1)
        startprev = temp;
      if (pos == m)
        start = temp;
      if (pos == n)
        end = temp;
      temp = temp->next;
      pos++;
    }
    ListNode *x = end->next;
    end->next = NULL;
    ListNode *reversed = reverseList(start);
    // return head;

    start->next = x;
    if (startprev)
      startprev->next = reversed;
    if (m == 1)
      return reversed;
    return head;
  }
};
