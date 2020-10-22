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
  string serialize(TreeNode *root) {
    if (!root)
      return "n";
    string res = to_string(root->val);
    res += " " + serialize(root->left);
    res += " " + serialize(root->right);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int i = 0;
    return _deserialize(data, i);
  }
  TreeNode *_deserialize(string &data, int &i) {
    int n = data.size();
    if (i >= n)
      return NULL;

    if (data[i] == 'n') {
      i += 2; // Move over "n" and space
      return NULL;
    }

    string t = "";
    while (i < n && data[i] != ' ')
      t += data[i++];

    i++; // Move over space
    TreeNode *node = new TreeNode(stoi(t));
    node->left = _deserialize(data, i);
    node->right = _deserialize(data, i);

    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
