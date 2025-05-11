#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5+7;
const int MOD = (int)1e9 + 7;

void solve() {
   string s;
   cin >> s;
   int n = sz(s);
   while(sz(s) < MAX) {
      s += s.substr(0, n);
   }
   int Q;
   cin >> Q;
   while(Q--) {
      string S; 
      cin >> S;
      int m = sz(S);
      cout << (s.substr(0, m) == S && m % n == 0 ? "Yes" : "No") << '\n';
   }
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int t = 1;
   // cin >> t;
   while(t--) {
      solve();
   }
   return 0;
}