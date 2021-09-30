#include "bits/stdc++.h"
using namespace std;
#define ll long long int
void IO() {
  #ifdef __DIPTO__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}
const ll N = 1005;
vector<pair<ll, ll>> adj[N];
ll lev[N], vis[N];
ll done[1005][1005];
int main(int argc, char const *argv[]) {
  IO();
  ll t, n, u, v, w;
  cin >> t;
  while (t--) {
    for (ll i = 0; i < N; i++) adj[i].clear(), lev[i] = 0, vis[i] = 0;
    cin >> n;
    for (ll i = 0; i < n - 1; i++) {
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }    
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) lev[j] = 0, vis[j] = 0, vis[i] = 0;
      queue<ll> q;
      q.push(i);
      vis[i] = 1;
      while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]) {
          if (!vis[v.first]) {
            vis[v.first] = 1;
            q.push(v.first);
            lev[v.first] = max(lev[u], v.second);
            done[i][v.first] = lev[v.first];
          }
        }
      }
    }
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        sum += done[i][j];
      }
    }
    cout << sum / 2 << endl;
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        done[i][j] = 0;
      }
    }
  }
  return 0;
}
