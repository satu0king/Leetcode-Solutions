/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    int c = 0;
    ListNode *temp = head;
    while (temp) {
      c++;
      temp = temp->next;
    }
    return f(head, c);
  }

  TreeNode *f(ListNode *&head, int n) {
    if (n == 0)
      return NULL;
    TreeNode *root = new TreeNode(0);
    root->left = f(head, n / 2);
    root->val = head->val;
    head = head->next;
    root->right = f(head, n - n / 2 - 1);
    return root;
  }
};
