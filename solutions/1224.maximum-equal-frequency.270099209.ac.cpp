class Solution {
public:
  int maxEqualFreq(vector<int> &nums) {
    vector<bool> elementsFound(1e5 + 1);
    int elementsCount = 0;
    int maxFreq = 1;
    int minFreq = 1;
    int ans = 1;
    vector<int> freq(1e5 + 1);
    vector<int> freqCount(1e5 + 1);
    freq[nums[0]]++;
    freqCount[1]++;
    elementsFound[nums[0]] = 1;
    elementsCount++;

    for (int i = 1; i < nums.size(); i++) {
      int num = nums[i];
      if (elementsFound[num]) {
        int oldFreq = freq[num];
        int newFreq = ++freq[num];
        freqCount[oldFreq]--;
        freqCount[newFreq]++;
        maxFreq = max(maxFreq, newFreq);
        if (freqCount[minFreq] == 0)
          minFreq++;
      } else {
        minFreq = 1;
        elementsCount++;
        elementsFound[num] = 1;
        freqCount[1]++;
        freq[num] = 1;
      }

      if (maxFreq - minFreq == 1 && freqCount[maxFreq] == 1)
        ans = i + 1;

      else if (maxFreq == 1)
        ans = i + 1;

      else if (minFreq == 1 && freqCount[maxFreq] == elementsCount - 1)
        ans = i + 1;

      else if (maxFreq == minFreq && freqCount[maxFreq] == 1)
        ans = i + 1;
    }

    return ans;
  }
};
