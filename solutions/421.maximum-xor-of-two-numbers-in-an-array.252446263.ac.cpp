struct Node {
  bool exists;
  int num;
  vector<Node *> edges;
  Node() : exists(false), num(-1), edges(2, NULL) {}
  void addNum(int &num, int i = 31) {
    if (i == -1) {
      exists = true;
      this->num = num;
    } else {
      bool one = num & (1 << i);
      if (!edges[one])
        edges[one] = new Node();
      edges[one]->addNum(num, i - 1);
    }
  }

  Node *one() { return edges[1]; }
  Node *two() { return edges[0]; }
};

// Complicated Solution --> See Discussion

class Solution {

public:
  int findMaximumXOR(vector<int> &nums) {
    Node root;
    for (int n : nums)
      root.addNum(n);

    return find(&root, &root);
  }

  int find(Node *root1, Node *root2) {

    int ans = 0;
    if ((root1->one() && root2->two()) || (root1->two() && root2->one())) {
      if (root1->one() && root2->two())
        ans = max(ans, find(root1->one(), root2->two()));
      if (root1->two() && root2->one())
        ans = max(ans, find(root1->two(), root2->one()));
    } else if (root1->one() && root2->one())
      ans = max(ans, find(root1->one(), root2->one()));
    else if (root1->two() && root2->two())
      ans = max(ans, find(root1->two(), root2->two()));
    else if (root1->exists && root2->exists)
      ans = max(ans, root1->num ^ root2->num);

    return ans;
  }
};
