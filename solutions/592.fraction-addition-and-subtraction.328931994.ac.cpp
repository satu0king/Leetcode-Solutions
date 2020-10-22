

class Solution {
public:
  string fractionAddition(string expression) {

    int num = 0;
    int den = 1;

    stringstream inp(expression);
    int a, b;
    char _;

    while (inp >> a >> _ >> b) {
      num = num * b + a * den;
      den *= b;
      int g = abs(__gcd(num, den));
      num /= g;
      den /= g;
    }

    return to_string(num) + "/" + to_string(den);
  }
};
