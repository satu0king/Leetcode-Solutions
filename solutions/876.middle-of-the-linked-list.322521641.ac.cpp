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
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast) {

      fast = fast->next;
      if (fast)
        fast = fast->next;
      else
        break;

      slow = slow->next;
    }

    return slow;
  }
};
