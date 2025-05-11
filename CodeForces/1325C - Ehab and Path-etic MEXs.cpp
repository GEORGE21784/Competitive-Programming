#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5 + 7;
const int MOD = (int)1e9 + 7;

vector<ii> t[MAX];

void solve() {
   int n;
   cin >> n;
   for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      t[u].push_back({v, i});
      t[v].push_back({u, i});
   }
   int x = 0;
   vector<int> ans(n - 1, -1);
   for(int i = 1; i <= n; i++) {
      if(sz(t[i]) > 2) {
         for(auto[v, id] : t[i]) {
            if(ans[id] == -1) 
               ans[id] = x++;
         }
         break;
      }
   }
   for(int i = 1; i <= n; i++) {
      for(auto[v, id] : t[i]) {
         if(ans[id] == -1) 
            ans[id] = x++;
      }
   }
   for(int nx : ans) cout << nx << '\n';
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