class Solution {
public:
  vector<int> constructRectangle(int area) {
    int width = ceil(sqrt(area));
    while (area % width)
      width++;
    return vector<int>{width, area / width};
  }
};
