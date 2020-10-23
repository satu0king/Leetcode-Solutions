class FirstUnique {
  unordered_map<int, int> mp;
  queue<int> q;

public:
  FirstUnique(vector<int> &nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int a : nums)
      if (mp[a]++ == 0)
        q.push(a);
  }

  int showFirstUnique() {
    while (q.size() && mp[q.front()] > 1)
      q.pop();
    if (q.empty())
      return -1;
    return q.front();
  }

  void add(int value) {
    if (mp[value]++ == 0)
      q.push(value);
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
