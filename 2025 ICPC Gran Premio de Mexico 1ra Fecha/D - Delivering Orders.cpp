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
   int m;
   cin >> m;
   vector<int> a(m + 1);
   for(int i = 1; i <= m; i++) {
      cin >> a[i];
   }
   int n;
   cin >> n;
   vector<vector<int>> g(n + 1, vector<int>(m + 1));
   for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
      cin >> g[i][j];
   }
   int mn = inf;
   vector<int> d(m + 1, -1);
   for(int j = 1; j <= m; j++) {
      int S = 0;
      for(int i = 1; i <= n; i++) {
         S += g[i][j];
      }
      if(S == 0) continue;
      int D = (a[j] + S - 1) / S;
      if(S * D == a[j]) D += 1;
      d[j] = D;
      a[j] -= (a[j] / S * S);
      mn = min(mn, d[j]);
   }
   int mn2 = inf;
   for(int j = 1; j <= m; j++) {
      if(d[j] != mn) continue;
      int S = 0;
      for(int i = 1; i <= n; i++) {
         S += g[i][j];
         if(S > a[j]) {
            mn2 = min(mn2, i);
            break;
         }
      }
   }
   cout << mn << ' ' << mn2 << '\n';
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