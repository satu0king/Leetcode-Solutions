class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int wordCount = 0;
    bool wordStart = true;
    for (int i = 0; i + searchWord.size() - 1 < sentence.size(); i++) {
      if (sentence[i] == ' ') {
        wordStart = true;
      } else if (wordStart) {
        wordCount++;
        wordStart = false;
        bool isPrefix = true;
        for (int k = 0; k < searchWord.size(); k++, i++) {
          if (sentence[i] == ' ') {
            wordStart = true;
            isPrefix = false;
            break;
          } else if (sentence[i] != searchWord[k]) {
            isPrefix = false;
            break;
          }
        }
        if (isPrefix)
          return wordCount;
      }
    }
    return -1;
  }
};
