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
  ListNode *insertionSortList(ListNode *head) {
    ListNode *dummy = new ListNode(INT_MIN);
    while (head) {
      ListNode *temp = head->next;
      insert(dummy, head);
      head = temp;
    }
    return dummy->next;
  }

  void insert(ListNode *dummy, ListNode *head) {
    ListNode *temp = dummy;

    while (temp->next && temp->next->val < head->val)
      temp = temp->next;

    head->next = temp->next;
    temp->next = head;
  }
};
