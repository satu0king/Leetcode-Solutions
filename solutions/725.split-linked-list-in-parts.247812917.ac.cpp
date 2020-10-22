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
  vector<ListNode *> splitListToParts(ListNode *root, int k) {

    int n = 0;
    ListNode *temp = root;
    while (temp) {
      n++;
      temp = temp->next;
    }

    int size = n / k;

    int bonus = size ? n % k : k;

    vector<ListNode *> ans;

    for (int i = 0; i < k; i++)
      root = f(ans, root, size + (i < bonus ? 1 : 0));

    return ans;
  }

  ListNode *f(vector<ListNode *> &ans, ListNode *root, int k) {

    ans.push_back(root);

    if (!root)
      return root;

    ListNode *temp = root;

    root = root->next;

    for (int i = 1; i < k; i++) {
      temp->next = root;
      temp = root;
      root = root->next;
    }

    temp->next = NULL;
    return root;
  }
};
