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
  ListNode *reverseKGroup(ListNode *head, int k) {

    int c = k;
    ListNode *temp = head;
    while (c && temp) {
      c--;
      temp = temp->next;
    }

    if (c)
      return head;

    ListNode *first = head;
    ListNode *t1 = NULL;

    for (int i = 0; i < k && head != NULL; i++) {
      ListNode *t2 = head->next;
      head->next = t1;
      t1 = head;
      head = t2;
    }

    if (head) {
      first->next = reverseKGroup(head, k);
    }

    return t1;
  }
};
