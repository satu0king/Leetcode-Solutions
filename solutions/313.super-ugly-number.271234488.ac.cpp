struct S {
  long long int value;
  int i;
  int prime;

  bool operator<(const S &rhs) const { return value > rhs.value; }
};
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {

    priority_queue<S> pq;
    vector<long long int> ans(1, 1);
    for (auto prime : primes)
      pq.push({prime, 1, prime});

    n--;
    while (n) {
      S temp = pq.top();
      pq.pop();

      if (temp.value != ans.back()) {
        ans.push_back(temp.value);
        n--;
      }

      pq.push({ans[temp.i] * temp.prime, temp.i + 1, temp.prime});
    }

    return ans.back();
  }
};
