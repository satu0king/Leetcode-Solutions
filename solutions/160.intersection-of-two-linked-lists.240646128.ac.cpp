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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;

    int flag1 = 0;
    int flag2 = 0;

    while (headA && headB) {
      if (headA == headB)
        return headA;
      headA = headA->next;
      headB = headB->next;

      if (headA == NULL && flag1 == 0) {
        flag1++;
        headA = ptr2;
      }

      if (headB == NULL && flag2 == 0) {
        flag2++;
        headB = ptr1;
      }
    }

    return NULL;
  }
};
