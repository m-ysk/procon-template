#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000007;

long long modinv(long long a) {
  long long b = MOD, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}
