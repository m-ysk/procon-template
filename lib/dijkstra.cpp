#include "bits/stdc++.h"
using namespace std;

const long long INF = 1000000000000000007;
// -------------------------------------------------------

// 少し多めに確保すること
// ぴったりだと正しく動かないので注意
const long long MAX_V = 1010101;

struct edge {
  long long to, cost;
};

using Pll = pair<long long, long long>;

long long V;
vector<edge> Graph[MAX_V];
long long dist[MAX_V];

void dijkstra(long long s) {
  priority_queue<Pll, vector<Pll>, greater<Pll>> que;

  // 0-indexedと1-indexedの両方に対応
  fill(dist, dist + MAX_V, INF);

  dist[s] = 0;
  que.push(Pll(0, s));

  while (!que.empty()) {
    auto elem = que.top();
    que.pop();

    auto cv = elem.second;

    if (elem.first > dist[cv]) {
      continue;
    }

    for (auto e : Graph[cv]) {
      if (dist[e.to] > dist[cv] + e.cost) {
        dist[e.to] = dist[cv] + e.cost;
        que.push(Pll(dist[e.to], e.to));
      }
    }
  }
}
