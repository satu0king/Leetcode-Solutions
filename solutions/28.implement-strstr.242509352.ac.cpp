class Solution {
public:
  int strStr(string haystack, string needle) {
    int n1 = haystack.size();
    int n2 = needle.size();
    if (n1 < n2)
      return -1;

    long long int h = 1;
    long long int hash = 0;
    long long int hash1 = 0;
    long long int p = 10e8 + 7;
    for (int i = 0; i < n2; i++) {
      if (i)
        h = (h * 26) % p;
      hash = (hash * 26 + haystack[i] - 'a') % p;
    }

    for (int i = 0; i < n2; i++)
      hash1 = (hash1 * 26 + needle[i] - 'a') % p;

    //         cout<<h<<endl;
    //         cout<<hash1<<endl;
    //         cout<<hash<<endl;

    if (hash == hash1)
      return 0;
    for (int i = n2; i < n1; i++) {
      hash = (hash - h * (haystack[i - n2] - 'a') + p) % p;
      hash = (hash * 26 + haystack[i] - 'a') % p;
      cout << hash << endl;
      if (hash == hash1)
        return i - n2 + 1;
    }

    return -1;
  }
};
