#include "bits/stdc++.h"
using namespace std;
#define ll long long int
void IO() {
  #ifdef __DIPTO__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}
ll isLeapYear(ll n) {
  if (n % 400 == 0) return 1;
  else if (n % 100 == 0) return 0;
  if (n % 4 == 0) return 1;
  else return 0;
} 
ll cnt[100][100][1000];
ll st[1000][1000];
int main(int argc, char const *argv[]) {
  IO();
  vector<ll> cntDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<pair<ll, ll>> daysNotLeap, daysLeap;
  for (ll i = 1; i <= 12; i++) {
    for (ll j = 1; j <= cntDays[i - 1]; j++) {
       daysNotLeap.push_back({j, i});
    }
  }
  cntDays[1]++;
  for (ll i = 1; i <= 12; i++) {
    for (ll j = 1; j <= cntDays[i - 1]; j++) {
      daysLeap.push_back({j, i});
   }
  }
  ll y, q, date, month, d1, d2, m1, m2;
  char ch;
  string s;
  cin >> y >> q;
 // map<pair<ll, pair<ll, char>>, ll> cnt;
 // map<pair<ll, ll>, ll> st;
  while (q--) {
    cin >> ch;
    if (ch == 'w') {
      ll idx = -1;
      cin >> date >> month >> s;
      if (!isLeapYear(y)) {
        for (auto i : daysNotLeap) {
        if (i == make_pair(date, month)) idx = 1;
        }
      } else {
        for (auto i : daysLeap) {
        if (i == make_pair(date, month)) idx = 1;
       }
      }
      
      if (idx == -1) {
        cout << -1 << endl;
        continue;
      }
      if (st[date][month] + s.size() > 1000) cout << 0 << endl;
      else {
        cout << 1 << endl;
        for (auto ch : s) {
          cnt[date][month][ch - '0']++;
          //cnt[{date, {month, ch}}]++;
        }
        st[date][month] += (ll) s.size();
      }
    } else {
      cin >> d1 >> m1 >> d2 >> m2 >> s;
      if (isLeapYear(y)) {
        ll sz = daysLeap.size();
        ll idx1 = -1;
        ll idx2 = -1;
        for (ll i = 0; i < sz; i++) {
          if (daysLeap[i] == make_pair(d1, m1)) {
            idx1 = i;
            break;
          }
        }
        for (ll i = sz - 1; i >= 0; i--) {
          if (daysLeap[i] == make_pair(d2, m2)) {
            idx2 = i;
            break;
          }
        }
        if (idx1 == -1 || idx2 == -1) {
          cout << -1 << endl;
          continue;
        }
       // map<char, ll> mp;
        ll mp[300];
        memset(mp, 0, sizeof mp);
        while (idx1 <= idx2) {
          ll d = daysLeap[idx1].first;
          ll m = daysLeap[idx1].second;
          for (char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch - '0'] += cnt[d][m][ch - '0'];
          }
          idx1++;
        }
        ll mp2[300];
        memset(mp2, 0, sizeof mp2);
        ll f = 1;
        for (char ch : s) mp2[ch - '0']++;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (mp2[ch - '0'] > mp[ch - '0']) f = 0;
        }
        cout << f << endl;
      } else {
        ll sz = daysNotLeap.size();
        ll idx1 = -1;
        ll idx2 = -1;
        for (ll i = 0; i < sz; i++) {
          if (daysNotLeap[i] == make_pair(d1, m1)) {
            idx1 = i;
            break;
          }
        }
        for (ll i = sz - 1; i >= 0; i--) {
          if (daysNotLeap[i] == make_pair(d2, m2)) {
            idx2 = i;
            break;
          }
        }
        if (idx1 == -1 || idx2 == -1) {
          cout << -1 << endl;
          continue;
        }
       // map<char, ll> mp;
        ll mp[300];
        memset(mp, 0, sizeof mp);
        while (idx1 <= idx2) {
          ll d = daysNotLeap[idx1].first;
          ll m = daysNotLeap[idx1].second;
          for (char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch - '0'] += cnt[d][m][ch - '0'];
          }
          idx1++;
        }
        ll mp2[300];
        memset(mp2, 0, sizeof mp2);
        ll f = 1;
        for (char ch : s) mp2[ch - '0']++;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (mp2[ch - '0'] > mp[ch - '0']) f = 0;
        }
        cout << f << endl;
        // for (char ch = 'a'; ch <= 'z'; ch++) {
        //   cout << ch << " " << mp[ch - '0'] << endl;
        // }
      }
    }
  }
  return 0;
} 