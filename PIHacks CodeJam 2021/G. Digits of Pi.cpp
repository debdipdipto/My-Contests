#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s = "1415926535897932";
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    ll sum = 0;
    n--;
    for (ll i = 0; i <= n; i++) sum += (s[i] - '0');
    cout << sum << endl;
  }
  return 0;
}