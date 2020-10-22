/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "";

    string res = to_string(root->val);
    if (root->left)
      res += " " + serialize(root->left);
    if (root->right)
      res += " " + serialize(root->right);

    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return NULL;

    int i = 0;
    return deserializeUtil(data, i, NULL, NULL);
  }

  TreeNode *deserializeUtil(string &data, int &i, TreeNode *minNode,
                            TreeNode *maxNode) {

    if (i >= data.size())
      return NULL;

    int i_temp = i;
    int nodeVal = getNextInt(data, i_temp);

    if (minNode && minNode->val >= nodeVal)
      return NULL;

    if (maxNode && maxNode->val <= nodeVal)
      return NULL;

    i = i_temp;

    TreeNode *root = new TreeNode(nodeVal);
    root->left = deserializeUtil(data, i, minNode, root);
    root->right = deserializeUtil(data, i, root, maxNode);

    return root;
  }

  int getNextInt(string &data, int &i) {
    string ans = "";
    int n = data.size();
    while (i < n && data[i] != ' ')
      ans += data[i++];

    if (i < n)
      i++; // jump over space;

    return stoi(ans);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
