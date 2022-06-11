/*
 * @Author : Debdip Das Dipto
 * This is an inefficient code which gets only 50 points.. :( 
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  string s;
  cin >> t;
  map<char, ll> sc;
  ll i = 1;
  for (char ch = 'a'; ch <= 'z'; ch++) sc[ch] = i, i++;
  while (t--) {
    cin >> s;
    ll n = s.size();
    s = " " + s;
    ll mat[n + 1][n + 1];
    ll pre[n + 1], h[n + 1], cnt[n + 1];
    for (ll i = 0; i <= n; i++) pre[i] = 0, h[i] = 0, cnt[i] = 0;
    for (ll i = 0; i <= n; i++) {
      for (ll j = 0; j <= n; j++) {
        mat[i][j] = 0;
      }
    }
    ll ans = 0, hs = 0, pw = 1, m = 1e9 + 7, p = 31;
    for (ll i = 1; i <= n; i++) {
      ans += (s[i] - 'a' + 1) * 100;
      pre[i] = ans;
      hs = (hs + (s[i] - 'a' + 1) * pw) % m;
      pw = (pw * p) % m;
      h[i] = hs;
    }
    ans = 0;
    for (ll i = 1; i <= n; i++) {
      hs = 0, pw = 1, m = 1e9 + 7, p = 31;
      for (ll j = i; j <= n; j++) {
        hs = (hs + (s[j] - 'a' + 1) * pw) % m;
        pw = (pw * p) % m;
        mat[i][j] = hs;
      }
    }
    for (ll i = 1; i <= n; i++) {
      for (ll j = i; j <= n; j++) {
        if (h[j - i + 1] == mat[i][j]) cnt[j - i + 1]++;
      }
    }
    for (ll i = 1; i <= n; i++) {
      ans = max(ans, cnt[i] * pre[i]);
    }
    cout << ans << endl;
    // cout << h[n] << endl;
  }
  return 0;
}
