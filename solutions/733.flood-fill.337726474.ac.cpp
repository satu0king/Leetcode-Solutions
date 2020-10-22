class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor, int oldColor = -1) {
    if (sr >= image.size() || sr < 0 || sc < 0 || sc >= image[0].size())
      return image;

    if (image[sr][sc] != oldColor && ~oldColor)
      return image;
    if (image[sr][sc] == newColor)
      return image;

    oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    floodFill(image, sr - 1, sc, newColor, oldColor);
    floodFill(image, sr + 1, sc, newColor, oldColor);
    floodFill(image, sr, sc + 1, newColor, oldColor);
    floodFill(image, sr, sc - 1, newColor, oldColor);
    return image;
  }
};
