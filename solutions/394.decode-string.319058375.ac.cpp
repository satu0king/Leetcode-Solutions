class Solution {
public:
  string decodeString(string s) {
    vector<int> numberStack;
    vector<string> wordStack;

    string current = "";
    int currentNumber = 0;

    for (char c : s) {
      if (isalpha(c)) {
        current += c;
      } else if (isdigit(c)) {
        if (currentNumber == 0) {
          wordStack.push_back(current);
          current = "";
        }
        currentNumber = currentNumber * 10 + (c - '0');
      } else if (c == '[') {
        numberStack.push_back(currentNumber);
        currentNumber = 0;
      } else if (c == ']') {
        int count = numberStack.back();
        numberStack.pop_back();
        string word = current;
        current = wordStack.back();
        wordStack.pop_back();
        while (count--)
          current += word;
      } else
        throw "Unrecognized Character!";
    }

    return current;
  }
};
