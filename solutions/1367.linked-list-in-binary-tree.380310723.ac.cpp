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
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (!head)
      return true;
    if (!root)
      return false;

    return f(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }

  bool f(ListNode *head, TreeNode *root) {
    if (!head)
      return true;
    if (!root)
      return false;

    if (head->val != root->val)
      return false;

    return f(head->next, root->left) || f(head->next, root->right);
  }
};
