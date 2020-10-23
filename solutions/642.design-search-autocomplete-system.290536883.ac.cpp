struct Sentence {
  string sentence;
  int frequency;
  Sentence(string sentence, int freq) : sentence(sentence), frequency(freq) {}
  bool operator<(const Sentence &other) {
    if (frequency != other.frequency)
      return frequency > other.frequency;
    else
      return sentence < other.sentence;
  }
};

bool cmp(Sentence *sentence1, Sentence *sentence2) {
  return *sentence1 < *sentence2;
}

struct Trie {
  vector<Trie *> nodes;
  Sentence *sentence;
  bool isSentence;
  vector<Sentence *> freq_sentences;
  Trie() : nodes(27, NULL), isSentence(false), sentence(NULL) {}

  void addSentence(Sentence *sentence, int i = 0) {
    addSentenceToList(sentence);
    if (i == sentence->sentence.size()) {
      isSentence = true;
      this->sentence = sentence;
      return;
    }
    char c = sentence->sentence[i];
    c = ind(c);
    if (!nodes[c])
      nodes[c] = new Trie();
    nodes[c]->addSentence(sentence, i + 1);
  }

  void addSentenceToList(Sentence *sentence) {
    auto it = find(freq_sentences.begin(), freq_sentences.end(), sentence);
    if (it == freq_sentences.end())
      freq_sentences.push_back(sentence);
    balance();
  }

  void balance() {
    sort(freq_sentences.begin(), freq_sentences.end(), cmp);
    if (freq_sentences.size() > 3)
      freq_sentences.pop_back();
  }

  int ind(char c) { return c == ' ' ? 26 : c - 'a'; }

  Trie *input(char c) {
    c = ind(c);
    if (!nodes[c])
      nodes[c] = new Trie();
    return nodes[c];
  }
};

class AutocompleteSystem {
  Trie *root;
  vector<Trie *> Path;
  string currentSentence;

public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
    root = new Trie();
    int n = sentences.size();
    for (int i = 0; i < n; i++)
      root->addSentence(new Sentence(sentences[i], times[i]));
    Path.push_back(root);
  }

  vector<string> input(char c) {

    auto current = Path.back();

    if (c == '#') {
      if (current->isSentence) {
        auto s = current->sentence;
        s->frequency++;
        for (auto n : Path) {
          n->addSentenceToList(s);
        }
      } else {
        // cout << "HIT " << currentSentence << endl;
        root->addSentence(new Sentence(currentSentence, 1));
      }
      Path = {root};
      currentSentence = "";
      return {};
    }
    currentSentence += c;

    auto next = current->input(c);
    Path.push_back(next);
    vector<string> answer;
    for (auto s : next->freq_sentences) {
      answer.push_back(s->sentence);
    }
    return answer;
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
