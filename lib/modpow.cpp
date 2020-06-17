#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
