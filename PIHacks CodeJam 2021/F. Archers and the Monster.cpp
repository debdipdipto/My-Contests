#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  double a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    double p = (a + b + c) / 2.0;
    double y = (p - a) * (p - b) * (p - c) / p;
    printf("%0.6f\n", sqrt(y));
  }
  return 0;
}