#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1000000007;

ll ppow(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n]++;
    }
    return res;
}