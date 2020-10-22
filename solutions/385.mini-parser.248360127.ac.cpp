/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
  NestedInteger deserialize(string s, int i = 0) { return parse(s, i); }

  NestedInteger parse(string &s, int &i) {
    if (s[i] == '[')
      return parseList(s, i);
    else
      return parseNumber(s, i);
  }

  NestedInteger parseNumber(string &s, int &i) {

    int n = 0;

    bool negative = false;

    while (s[i] != ',' && s[i] != ']' && i != s.size())
      if (s[i] == '-') {
        negative = true;
        i++;
      } else
        n = n * 10 + s[i++] - '0';

    return NestedInteger(n * (negative ? -1 : 1));
  }

  NestedInteger parseList(string &s, int &i) {

    NestedInteger ans;
    i++;
    while (s[i] != ']') {
      ans.add(parse(s, i));
      if (s[i] == ',')
        i++;
    }
    i++;

    return ans;
  }
};
