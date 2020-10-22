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
  ListNode *sortList(ListNode *head) {

    int c = 0;
    ListNode *temp = head;
    while (temp) {
      temp = temp->next;
      c++;
    }

    // cout<<c<<endl;

    if (c <= 1)
      return head;

    temp = head;
    c = c / 2 - 1;
    while (c--)
      temp = temp->next;

    ListNode *temp2 = temp->next;
    temp->next = NULL;

    head = sortList(head);
    temp2 = sortList(temp2);

    ListNode *temp3 = new ListNode(0);
    ListNode *temp4 = temp3;

    while (head && temp2) {

      int v = -1;
      if (head->val > temp2->val) {
        v = temp2->val;
        temp2 = temp2->next;
      } else {
        v = head->val;
        head = head->next;
      }

      temp4->next = new ListNode(v);
      temp4 = temp4->next;
    }
    while (head) {

      int v = head->val;
      head = head->next;

      temp4->next = new ListNode(v);
      temp4 = temp4->next;
    }
    while (temp2) {

      int v = temp2->val;
      temp2 = temp2->next;

      temp4->next = new ListNode(v);
      temp4 = temp4->next;
    }

    return temp3->next;
  }
};
