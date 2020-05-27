#include "bits/stdc++.h"
using namespace std;

const long long INF = 1000000000000000007;
// -------------------------------------------------------
const long long MAX_N = 16;
// 1-indexed
const long long Start = 1;

long long N;
// cost[from][to]
long long cost[MAX_N][MAX_N];

long long dp[1 << MAX_N][MAX_N];

long long rec(long long s, long long v) {
  if (dp[s][v] != -1) {
    return dp[s][v];
  }

  if (s == (1 << N) - 1 && v == Start) {
    return dp[s][v] = 0;
  }

  long long res = INF;
  // 1-indexed
  for (long long i = 1; i <= N; ++i) {
    if (s & (1 << (i - 1))) {
      continue;
    }
    res = min(res, rec(s | (1 << (i - 1)), i) + cost[v][i]);
  }
  return dp[s][v] = res;
}

void init_dp() {
  memset(dp, -1, sizeof(dp));
  for (long long i = 0; i < MAX_N; ++i) {
    for (long long j = 0; j < MAX_N; ++j) {
      cost[i][j] = INF;
    }
  }
}

/*
Sample Input (1-indexed)
5 8
1 2 3
2 3 5
3 1 4
3 4 5
4 5 3
5 2 6
5 1 7
1 4 4

Sample Output
22
*/

int main() {
  init_dp();

  long long E;
  cin >> N >> E;
  for (long long i = 0; i < E; ++i) {
    long long from, to, cst;
    cin >> from >> to >> cst;
    cost[from][to] = cst;
  }

  cout << rec(0, 1) << endl;
}
