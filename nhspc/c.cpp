/*
 * @Author : Debdip Das Dipto
 * In this code my total logic is wrong, but somehow I got 4 points.. :3 
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long int
vector<ll> adj[100003];
ll type[100003], vis[100003];
string p;
void dfs(ll s) {
  if (vis[s]) return;
  vis[s] = 1;
  p.push_back(type[s] + '0');
  for (ll i : adj[s]) {
    dfs(i);
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, u, v;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) cin >> type[i];
  for (ll i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  vector<string> vv;
  ll ans = 0;
  vis[1] = 1;
  string b;
  b += (type[1] + '0');
  for (ll i : adj[1]) {
    p.clear();
    dfs(i);
    vv.push_back(b + p);
  }
  for (auto i : vv) {
    ll c = 0;
    for (ll j : i) {
      if (j == '0') c++;
      else c = 0;
      ans++;
      if (c == m) break;
    }
  }
  if (type[1] == 1) {
    ans -= (adj[1].size() - 1);
  }
  cout << ans << " " << adj[1].size() << endl;
  return 0;
}




