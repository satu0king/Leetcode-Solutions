
typedef long long int ll;

const ll MOD = 1e9 + 7;

ll add(ll a, ll b) {
  ll res = a + b;
  if (res >= MOD)
    return res - MOD;
  return res;
}

ll mul(ll a, ll b) {
  long long res = a;
  res *= b;
  if (res >= MOD)
    return res % MOD;
  return res;
}

struct matrix {
  ll SZ;
  vector<vector<ll>> arr;
  matrix(ll s) {
    SZ = s;
    arr.resize(s, vector<ll>(s));
  }
  void reset() {
    for (ll i = 0; i < SZ; i++) {
      for (ll j = 0; j < SZ; j++) {
        arr[i][j] = 0;
      }
    }
  }

  void makeiden() {
    reset();
    for (ll i = 0; i < SZ; i++) {
      arr[i][i] = 1;
    }
  }

  matrix operator+(const matrix &o) const {
    matrix res(o.SZ);
    for (ll i = 0; i < SZ; i++) {
      for (ll j = 0; j < SZ; j++) {
        res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
      }
    }
    return res;
  }

  matrix operator*(const matrix &o) const {
    matrix res(o.SZ);
    for (ll i = 0; i < SZ; i++) {
      for (ll j = 0; j < SZ; j++) {
        res.arr[i][j] = 0;
        for (ll k = 0; k < SZ; k++) {
          res.arr[i][j] = add(res.arr[i][j], mul(arr[i][k], o.arr[k][j]));
        }
      }
    }
    return res;
  }

  void prll() {
    for (ll i = 0; i < SZ; i++) {
      for (ll j = 0; j < SZ; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }
};

matrix power(matrix a, ll b) {
  matrix res = a;
  b--;
  while (b) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

class Solution {

public:
  ll knightDialer(ll N) {
    matrix m(10);

    if (N == 1)
      return 10;

    m.arr[0][4] = 1;
    m.arr[0][6] = 1;

    m.arr[1][6] = 1;
    m.arr[1][8] = 1;

    m.arr[2][7] = 1;
    m.arr[2][9] = 1;

    m.arr[3][4] = 1;
    m.arr[3][8] = 1;

    m.arr[4][3] = 1;
    m.arr[4][9] = 1;
    m.arr[4][0] = 1;

    m.arr[6][1] = 1;
    m.arr[6][7] = 1;
    m.arr[6][0] = 1;

    m.arr[7][2] = 1;
    m.arr[7][6] = 1;

    m.arr[8][3] = 1;
    m.arr[8][1] = 1;

    m.arr[9][2] = 1;
    m.arr[9][4] = 1;

    m = power(m, N - 1);

    ll sum = 0;
    for (auto &v : m.arr)
      for (auto &n : v)
        sum = add(sum, n);

    return sum;
  }
};
