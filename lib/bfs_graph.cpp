#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000007;
// -------------------------------------------------------

const long long MAX_V = 1010101;

long long V;
vector<long long> Graph[MAX_V];
long long dist[MAX_V];

void bfs(long long start) {
  queue<long long> que;
  // 0-indexed
  fill(dist, dist + V, INF);
  // 1-indexed
  // fill(dist + 1, dist + 1 + V, INF);

  dist[start] = 0;
  que.push(start);

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    for (auto nv : Graph[cur]) {
      if (dist[nv] != INF) {
        continue;
      }

      dist[nv] = dist[cur] + 1;
      que.push(nv);
    }
  }
}
