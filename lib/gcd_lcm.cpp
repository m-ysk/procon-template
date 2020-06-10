
#include "bits/stdc++.h"
using namespace std;

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  cout << gcd(120, 115) << endl;
  cout << lcm(15, 20) << endl;
}
