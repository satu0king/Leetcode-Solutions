class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> answer(k);
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 0; i <= k; i++) {
      int j = k - i;
      if (i <= n1 && j <= n2) {
        vector<int> ans1 = maxSingleNumber(nums1, i); // best of size i - O(n)
        vector<int> ans2 =
            maxSingleNumber(nums2, j);       // best of size k - i - O(n)
        vector<int> ans = merge(ans1, ans2); // merging both - O(n)

        answer = max(ans, answer); // maximize answer - O(n)
      }
    }
    return answer;
  }

  vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;

    int i = 0;
    int j = 0;
    int k = 0;

    int n1 = nums1.size();
    int n2 = nums2.size();

    // Eventhough there are two nested loops, I believe this is linear as the
    // second loop can only run once per element
    while (i < n1 && j < n2) {
      if (nums1[i] > nums2[j])
        ans.push_back(nums1[i++]);
      else if (nums1[i] < nums2[j])
        ans.push_back(nums2[j++]);
      else { // Both are equal, we need to pick the one that is better in the
             // future
        int i1 = i + 1;
        int j1 = j + 1;
        int larger = 0;

        while (i1 < n1 && j1 < n2 && !larger) {
          if (nums1[i1] == nums2[j1]) {
            if (nums1[i1] <
                nums1[i]) // This number is less than the current stopping
                          // position, so we would pick that instead
              break;
            i1++;
            j1++;
          } else if (nums1[i1] > nums2[j1]) // nums1 is better to pick
            larger = -1;
          else
            larger = 1; // nums2 is better to pick
        }

        if (i1 == n1)
          larger = 1;
        if (j1 == n2)
          larger = -1;

        if (larger == -1)
          ans.push_back(nums1[i++]);
        else
          ans.push_back(nums2[j++]);
      }
    }

    // Push Remaining elements
    while (i < n1)
      ans.push_back(nums1[i++]);

    while (j < n2)
      ans.push_back(nums2[j++]);

    return ans;
  }

  vector<int> maxSingleNumber(vector<int> &nums1, int k) {

    vector<int> stack;
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      // Pop elements from the stack if current element is greater than head of
      // the stack We can pop only if remaining elements in nums1 + remaining
      // elements in stack after popping is greater than or equal to k
      while (!stack.empty() &&
             (stack.back() < nums1[i] && (stack.size() - 1) + (n - i) >= k))
        stack.pop_back();

      // Push if less than k elements
      if (stack.size() < k)
        stack.push_back(nums1[i]);
    }
    return stack;
  }
};
