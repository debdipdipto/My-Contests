#include "bits/stdc++.h"
using namespace std;
#define ll long long int
void IO() {
  #ifdef __DIPTO__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}
const ll M = 998244353;
ll bigMod(ll a, ll b) {
  if (b == 0) return 1 % M;
  ll x = bigMod(a, b / 2);
  x = (x * x) % M;
  if (b % 2 == 1) x = (x * a) % M;
  return x;
}
const ll N = 1e6 + 5;
ll fact[N];
ll modInv(ll a) {
  a = fact[a];
  return bigMod(a, M - 2);
}
int main(int argc, char const *argv[]) {
  IO();
  ll n, m, k;
  cin >> n >> m;
  vector<ll> v;
  ll one = 0, two = 0;
  for (ll i = 0; i < n; i++) {
    cin >> k;
    one += (k == 1);
    two += (k == 2);
  }
  fact[0] = 1;
  for (ll i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i);
    fact[i] %= M;
  }
  ll sum = 0;
  for (ll i = 2; i <= n; i++) {
    if (one >= i - 1) {
      ll cnt1 = one - (i - 1);
      ll cnt2 = two - 1;
      ll N = n - i;
      ll g = fact[N] * modInv(cnt1);
      g %= M;
      g *= modInv(cnt2);
      g %= M;
      sum += (i * g);
      sum %= M;
    }
    if (two >= i - 1) {
      ll cnt1 = one - 1;
      ll cnt2 = two - (i - 1);
      ll N = n - i;
      ll g = fact[N] * modInv(cnt1);
      g %= M;
      g *= modInv(cnt2);
      g %= M;
      sum += (i * g);
      sum %= M;
    }
  }
  cout << sum % M << endl;
  return 0;
}
