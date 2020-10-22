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
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode *> map;

    map[0] = dummy;

    int sum = 0;
    while (head) {
      sum += head->val;
      if (map.count(sum)) {
        ListNode *prev = map[sum];
        int t = sum;
        ListNode *temp = prev->next;
        while (temp != head) {
          t += temp->val;
          map.erase(t);
          temp = temp->next;
        }
        prev->next = head->next;
      } else
        map[sum] = head;
      head = head->next;
    }

    return dummy->next;
  }
};
