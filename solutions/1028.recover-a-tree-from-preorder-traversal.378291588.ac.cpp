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
  TreeNode *recoverFromPreorder(string S) {
    vector<pair<int, int>> parsedData = parse(S);
    int i = 0;
    return constructTree(parsedData, i);
  }

  TreeNode *constructTree(vector<pair<int, int>> &parsedData, int &i,
                          int depth = 0) {
    if (i == parsedData.size())
      return NULL;
    auto [d, v] = parsedData[i];
    if (d != depth)
      return NULL;
    i++;
    TreeNode *root = new TreeNode(v);
    root->left = constructTree(parsedData, i, depth + 1);
    root->right = constructTree(parsedData, i, depth + 1);
    return root;
  }

  vector<pair<int, int>> parse(string &S) {
    int i = 0;
    int n = S.size();
    vector<pair<int, int>> result;
    while (i < n) {
      int depth = 0;
      while (S[i] == '-') {
        depth++;
        i++;
      }
      string num;
      while (i < n && isdigit(S[i]))
        num += S[i++];
      result.push_back({depth, stoi(num)});
    }
    return result;
  }
};
