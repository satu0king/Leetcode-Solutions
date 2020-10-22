// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
  int rand10() {
    int randNum = 0;
    for (int i = 0; i < 3; i++)
      randNum = randNum * 7 + rand7() - 1;
    return randNum % 10 + 1;
  }
};
