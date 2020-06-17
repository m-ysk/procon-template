#include "bits/stdc++.h"
using namespace std;

const int MAX_N = 1e6 + 1000;

int nth_prime[MAX_N];
int is_prime[MAX_N];
int min_factor[MAX_N];

void sieve() {
  int n = MAX_N;
  int p = 0;
  for (int i = 0; i <= n; ++i) {
    is_prime[i] = true;
  }

  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      nth_prime[p] = i;
      ++p;
      min_factor[i] = i;

      for (int j = 2 * i; j <= n; j += i) {
        if (is_prime[j]) {
          is_prime[j] = false;
          min_factor[j] = i;
        }
      }
    }
  }

  // n以下の素数の個数が必要な場合はpをreturn
  // return p;
}

map<int, int> fast_prime_factorize(int n) {
  map<int, int> res;
  while (n > 1 && n % min_factor[n] == 0) {
    ++res[min_factor[n]];
    n /= min_factor[n];
  }
  return res;
}
