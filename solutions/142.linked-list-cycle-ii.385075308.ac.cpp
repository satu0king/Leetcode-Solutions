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
  ListNode *nxt(ListNode *curr) {
    if (curr == NULL)
      return NULL;
    return curr->next;
  }
  ListNode *detectCycle(ListNode *head) {
    ListNode *hare = nxt(nxt(head));
    ListNode *tortoise = nxt(head);
    while (hare != NULL && tortoise != hare) {
      hare = nxt(nxt(hare));
      tortoise = nxt(tortoise);
    }
    if (hare == NULL)
      return NULL;
    // cout << tortoise->val << endl;
    hare = head;
    while (hare != tortoise) {
      hare = nxt(hare);
      tortoise = nxt(tortoise);
    }
    return hare;
  }
};
