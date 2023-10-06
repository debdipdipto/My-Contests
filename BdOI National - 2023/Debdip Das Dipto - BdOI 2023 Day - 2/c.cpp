#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dist[3001][3001];
vector<ll> flatArray = {INT_MAX};
ll vis[20001];
vector<ll> adj[20001];
void dfs(ll s) {
  if (vis[s]) return;
  vis[s] = 1;
  flatArray.push_back(s);
  for (ll i : adj[s]) dfs(i);
}
ll prefSum[2001], suffSum[2001];
ll midSumF[2001][2001], midSumR[2001][2001];
int main() {
  ll n, k, u, v;
  cin >> n;
  vector<ll> a = {INT_MAX}, ra;
  for (ll i = 1; i <= n; i++) {
    cin >> k;
    a.push_back(k);
  }
  vector<ll> mainAns(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (ll i = 1; i <= n; i++) {
    if (adj[i].size() == 1) {
      dfs(i);
      break;
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j < i; j++) {
      prefSum[i] += (i - j) * a[flatArray[j]];
    }
  }
  for (ll i = n; i >= 1; i--) {
    for (ll j = i + 1; j <= n; j++) {
      suffSum[i] += (j - i) * a[flatArray[j]];
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = i + 1; j <= n; j++) {
      midSumF[i][j - i] += midSumF[i][j - i - 1] + (j - i) * a[flatArray[j]];
    }
  }
  for (ll i = n; i >= 1; i--) {
    for (ll j = i - 1; j >= 1; j--) {
      midSumR[i][i - j] += midSumR[i][i - j - 1] + (i - j) * a[flatArray[j]];
    }
  }
  /*
  for (ll i = 1; i <= n; i++) cout << prefSum[i] << " ";
  cout << endl;
  for (ll i = 1; i <= n; i++) cout << suffSum[i] << " ";
  cout << endl;
  for (ll i : flatArray) cout << i << " ";
  cout << endl;
  ll q;
  cin >> q;
  while (q--) {
    ll u, v;
    cin >> u >> v;
    cout << midSumR[u][v] << endl;
  }
  */
  for (ll i = 1; i <= n; i++) {
    ll ans = 0;
    for (ll p = 1; p <= n; p++) {
      if (p > i) {
        ans = prefSum[p] + suffSum[i];
        ll len = i - p - 1;
        ll mid = len / 2;
        if (mid & 1) mid++;
        ans += midSumF[i][mid];
        ll rem = len - mid;
        ans += midSumR[p][rem];
      } else {
        ans = prefSum[i] + suffSum[p];
        ll len = p - i - 1;
        ll mid = len / 2;
        if (mid & 1) mid++;
        ans += midSumF[p][mid];
        ll rem = len - mid;
        ans += midSumR[i][rem];
      }
    }
    mainAns[flatArray[i]] = ans;
  }
  for (ll i = 1; i <= n; i++) {
    cout << mainAns[i] << " ";
  }
  cout << endl;


  /*
  for (ll i = 1; i <= n; i++) {
    ll ans = 0;
    for (ll p = 1; p <= n; p++) {
      if (i == p) continue;
      if (p < i) {
        ans = prefSum[p] + suffSum[i];
        ll lenght = i - p - 1;
        ll mid = (lenght / 2);
        ll l = i + 1, r = p - 1;
        if (lenght & 1) mid++;
        ans += midSum[i][i + lenght];
        ll rnew = (n + 1 - r);
        ans += rmidSum[rnew][rnew + lenght - mid];
      } else if (p > i) {
        ans = prefSum[i] + suffSum[p];
        ll length = p - i - 1;
        ll mid = (length / 2);
        ll l = p + 1, r = i - 1;
        if (length & 1) mid++;
        ans += midSum[l][l + mid];
        ll rnew = (n + 1 - r);
        ans += rmidSum[rnew][rnew + length - mid];
      }
    }
    mainAns[flatArray[i]] = ans;
  }
  for (ll i = 1; i <= n; i++) {
    cout << mainAns[i] << " ";
  }
  cout << endl;*/
  return 0;
}
