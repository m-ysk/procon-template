#include "bits/stdc++.h"
using namespace std;

const long long INF = 1000000000000000007;
// -------------------------------------------------------

const int MAX_V = 330;
int V;

long long dist[MAX_V][MAX_V];

void init_dist() {
  for (int i = 0; i < MAX_V; ++i) {
    for (int j = 0; j < MAX_V; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
      }
    }
  }
}

void warshall_floyd() {
  // 1-indexed
  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}
