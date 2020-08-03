#include <bits/stdc++.h>
using namespace std;

template <class T>
class BIT {
  vector<T> data[2];
  T ZERO = 0;

  void sub_add(int p, int a, T x) {
    for (int i = a; i < (int)data[p].size(); i += (i & -i)) {
      data[p][i] = data[p][i] + x;
    }
  }

  T sub_sum(int p, int a) {
    T res = 0;
    for (int i = a; i > 0; i -= (i & -i)) {
      res += data[p][i];
    }
    return res;
  }

 public:
  BIT(int n) { init(n); }
  void init(int n) {
    for (int i = 0; i < 2; ++i) {
      data[i].assign(n + 1, ZERO);
    }
  }

  void add(int a, int b, T x) {
    sub_add(0, a, x * -(a - 1));
    sub_add(1, a, x);
    sub_add(0, b, x * (b - 1));
    sub_add(1, b, x * (-1));
  }

  T sum(int a, int b) {
    return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) -
           sub_sum(1, a - 1) * (a - 1);
  }
};
