class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    return area(A, B, C, D) - interesectingArea(A, B, C, D, E, F, G, H) +
           area(E, F, G, H);
  }

  int interesectingArea(int A, int B, int C, int D, int E, int F, int G,
                        int H) {
    int b = max(B, F);
    int a = max(A, E);
    int c = min(C, G);
    int d = min(D, H);

    if (d < b || c < a)
      return 0;

    return area(a, b, c, d);
  }

  int area(int A, int B, int C, int D) { return (D - B) * (C - A); }
};
