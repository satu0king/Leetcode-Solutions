class ProductOfNumbers {
  vector<int> prefixProduct;

public:
  ProductOfNumbers() : prefixProduct(1, 1) {}

  void add(int num) {
    if (num == 0)
      prefixProduct.assign(1, 1);
    else
      prefixProduct.push_back(prefixProduct.back() * num);
  }

  int getProduct(int k) {
    if (k >= prefixProduct.size())
      return 0;
    return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
