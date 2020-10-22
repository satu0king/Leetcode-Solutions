class Solution {
public:
  int nextGreaterElement(int n) {

    vector<long long int> n1;
    long long int t = n;
    do {
      n1.push_back(t % 10);
    } while (t = t / 10);

    reverse(n1.begin(), n1.end());
    next_permutation(n1.begin(), n1.end());
    reverse(n1.begin(), n1.end());

    long long int n2 = 0;
    while (n1.size()) {
      n2 = n2 * 10 + n1.back();
      n1.pop_back();
    }

    if (n2 <= n || n2 > INT_MAX)
      return -1;
    return n2;
  }
};
