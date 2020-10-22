class Cashier {
  int n;
  int discount;
  int i = 0;
  vector<int> priceMap;

public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
      : n(n), discount(discount), i(0), priceMap(300) {
    for (int i = 0; i < products.size(); i++)
      priceMap[products[i]] = prices[i];
  }

  double getBill(vector<int> product, vector<int> amount) {

    double bill = 0;
    for (int i = 0; i < product.size(); i++)
      bill += priceMap[product[i]] * amount[i];

    if (++i % n == 0)
      bill -= discount * bill / 100;

    return bill;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
