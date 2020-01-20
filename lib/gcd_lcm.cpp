
#include "bits/stdc++.h"
using namespace std;

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    cout << gcd(120, 115) << endl;
    cout << lcm(15, 20) << endl;
}
