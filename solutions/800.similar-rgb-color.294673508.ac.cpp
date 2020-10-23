vector<int> options = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                       0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

class Solution {
public:
  string similarRGB(string color) {
    int r = stoi(color.substr(1, 2), 0, 16);
    int g = stoi(color.substr(3, 2), 0, 16);
    int b = stoi(color.substr(5, 2), 0, 16);
    char result[100];
    result[0] = '#';
    sprintf(result + 1, "%02x", closest(r)); // convert number to hex
    sprintf(result + 3, "%02x", closest(g)); // convert number to hex
    sprintf(result + 5, "%02x", closest(b)); // convert number to hex
    return result;
  }

  int closest(int c) {
    int op1 = *lower_bound(options.begin(), options.end(), c);
    int op2 = *prev(upper_bound(options.begin(), options.end(), c));

    if (abs(op1 - c) < abs(op2 - c))
      return op1;
    return op2;
  }
};
