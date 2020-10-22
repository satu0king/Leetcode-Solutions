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
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
      p1 = p2->next;
      p2->next = head2;
      head2 = p2;
      p2 = p1;
    }

    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1;) {
      auto t = p1->next;
      p1 = p1->next = p2;
      p2 = t;
    }

    // for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
  }
};
