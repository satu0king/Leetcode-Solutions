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
  int numComponents(ListNode *head, vector<int> &G) {
    int ans = 0;
    bool connected = false;
    unordered_set<int> set(G.begin(), G.end());

    while (head) {
      if (set.count(head->val)) {
        if (!connected)
          ans++;
        connected = true;
      } else
        connected = false;
      head = head->next;
    }

    return ans;
  }
};
