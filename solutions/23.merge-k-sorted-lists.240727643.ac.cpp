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
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    set<pair<int, int>> mp;
    int n = lists.size();

    ListNode *dummy = new ListNode(0);
    ListNode *ptr = dummy;

    for (int i = 0; i < n; i++)
      if (lists[i])
        mp.emplace(lists[i]->val, i);

    while (!mp.empty()) {
      auto it = mp.begin();
      int i = (*it).second;
      int v = (*it).first;
      mp.erase(it);
      auto &node = lists[i];

      ptr->next = new ListNode(node->val);
      ptr = ptr->next;

      lists[i] = node->next;

      if (lists[i])
        mp.emplace(lists[i]->val, i);
    }
    return dummy->next;
  }
};
