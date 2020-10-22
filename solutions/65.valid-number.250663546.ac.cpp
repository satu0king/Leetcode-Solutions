class Solution {
public:
  bool isNumber(string s) {
    s = strip(s);

    vector<unordered_map<string, int>> stateTransistions(10);

    stateTransistions[0] = {{"sign", 1}, {"digit", 2}, {"dot", 8}};

    stateTransistions[1] = {{"digit", 2}, {"dot", 8}};

    stateTransistions[2] = {{"digit", 2}, {"dot", 3}, {"exp", 5}};

    stateTransistions[3] = {{"digit", 4}, {"exp", 5}};

    stateTransistions[4] = {{"digit", 4}, {"exp", 5}};

    stateTransistions[5] = {{"digit", 7}, {"sign", 6}};

    stateTransistions[6] = {{"digit", 7}};

    stateTransistions[7] = {{"digit", 7}};
    stateTransistions[8] = {{"digit", 4}};

    unordered_set<int> acceptStates = {2, 3, 4, 7};

    int currentState = 0;

    for (char c : s) {
      string transition = "";
      if (c >= '0' && c <= '9')
        transition = "digit";
      else if (c == 'e')
        transition = "exp";
      else if (c == '+' || c == '-')
        transition = "sign";
      else if (c == '.')
        transition = "dot";

      if (stateTransistions[currentState].count(transition))
        currentState = stateTransistions[currentState][transition];
      else
        return false;
    }

    return acceptStates.count(currentState);
  }

  string strip(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l <= r && s[l] == ' ')
      l++;
    while (l <= r && s[r] == ' ')
      r--;

    return s.substr(l, r - l + 1);
  }
};
