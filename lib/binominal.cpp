#include "bits/stdc++.h"
using namespace std;

long long binom[55][55];

// パスカルの三角形を用いて二項係数を求める
void binom_init() {
  binom[0][0] = 1;
  binom[1][0] = 1;
  binom[1][1] = 1;

  for (int i = 2; i <= 50; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }
}