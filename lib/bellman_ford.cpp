#include "bits/stdc++.h"
using namespace std;

const long long INF = 1000000000000000007;
// -------------------------------------------------------

const long long MAX_E = 10101;
const long long MAX_V = 10101;

struct edge {
  long long from, to, cost;
};

edge es[MAX_E];

long long dist[MAX_V];
long long V, E;

// 負の閉路が存在する場合はtrueを返す
bool shortest_path(long long s) {
  for (int i = 1; i <= V; i++) dist[i] = INF;

  dist[s] = 0;

  long long cnt = 0;
  while (true) {
    bool updated = false;
    for (int i = 1; i <= E; i++) {
      edge e = es[i];
      if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        updated = true;
      }
    }
    if (!updated) break;

    ++cnt;
    if (cnt >= V) {
      // V回目のループで更新が起こった場合、負の閉路が存在するのでtrueを返す
      return true;
    }
  }

  return false;
}
