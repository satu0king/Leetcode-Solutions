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
  ListNode *deleteNodes(ListNode *head, int m, int n) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *current = dummyHead;
    while (head) {
      int t = m;
      while (t-- && head) {
        current->next = head;
        current = head;
        head = head->next;
      }
      t = n;
      while (t-- && head) {
        head = head->next;
      }
    }
    current->next = NULL;
    return dummyHead->next;
  }
};
