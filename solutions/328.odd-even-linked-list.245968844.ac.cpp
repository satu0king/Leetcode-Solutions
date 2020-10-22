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
  ListNode *oddEvenList(ListNode *head) {
    ListNode *odd = new ListNode(0);
    ListNode *even = new ListNode(0);

    ListNode *oddHead = odd;
    ListNode *evenHead = even;

    bool isOdd = true;
    while (head) {
      if (isOdd) {
        oddHead->next = head;
        oddHead = head;
      } else {
        evenHead->next = head;
        evenHead = head;
      }
      isOdd = !isOdd;
      head = head->next;
    }

    oddHead->next = even->next;
    evenHead->next = NULL;
    return odd->next;
  }
};
