class Solution {
public:
  string getHint(string secret, string guess) {
    vector<int> count(10);
    for (char c : secret)
      count[c - '0']++;

    int bulls = 0;
    int n = secret.size();
    for (int i = 0; i < n; i++)
      if (secret[i] == guess[i]) {
        bulls++;
        count[secret[i] - '0']--;
      }

    int cows = 0;

    for (int i = 0; i < n; i++)
      if (secret[i] != guess[i] && count[guess[i] - '0']) {
        cows++;
        count[guess[i] - '0']--;
      }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
