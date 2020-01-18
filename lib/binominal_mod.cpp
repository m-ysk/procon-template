#include "bits/stdc++.h"
using namespace std;

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const int MAX = 1010101;

long long fac[MAX], finv[MAX], inv[MAX];

void binom_init()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long binom(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    binom_init();
    cout << binom(1000000, 53564) << endl;
}
