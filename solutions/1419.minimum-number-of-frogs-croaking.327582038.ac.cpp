class Solution {
public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int c = 0, r = 0, o = 0, a = 0, k = 0, in_use = 0, answer = 0;
    for (char d : croakOfFrogs) {
      switch (d) {
      case 'c':
        c++;
        in_use++;
        break;
      case 'r':
        r++;
        break;
      case 'o':
        o++;
        break;
      case 'a':
        a++;
        break;
      case 'k':
        k++;
        in_use--;
        break;
      default:
        return -1;
      }
      answer = max(answer, in_use);
      if ((c < r) || (r < o) || (o < a) || (a < k))
        return -1;
    }
    if (in_use == 0 && c == r && c == o && c == a && c == k)
      return answer;

    return -1;
  }
};
