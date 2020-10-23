class Solution {
public:
  vector<string> beforeAndAfterPuzzles(vector<string> &phrases) {
    vector<string> ans;

    int n = phrases.size();

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {

        stringstream phrase1(phrases[i]);
        stringstream phrase2(phrases[j]);

        vector<string> phrase1_words;
        vector<string> phrase2_words;

        string temp;

        while (phrase1 >> temp)
          phrase1_words.push_back(temp);
        while (phrase2 >> temp)
          phrase2_words.push_back(temp);

        // cout << "HIT" << endl;

        if (phrase1_words.back() == phrase2_words.front()) {
          string res = phrase1_words[0];
          for (int k = 1; k < phrase1_words.size(); k++)
            res += " " + phrase1_words[k];
          for (int k = 1; k < phrase2_words.size(); k++)
            res += " " + phrase2_words[k];
          ans.push_back(res);
        }
        if (phrase1_words.front() == phrase2_words.back()) {
          string res = phrase2_words[0];
          for (int k = 1; k < phrase2_words.size(); k++)
            res += " " + phrase2_words[k];
          for (int k = 1; k < phrase1_words.size(); k++)
            res += " " + phrase1_words[k];
          ans.push_back(res);
        }
      }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};
