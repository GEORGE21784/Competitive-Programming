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

// 0 - red
// 1 - black
vector<ii> t[MAX];
int vis[MAX];

int binpow(int a, int b) {
   int ans = 1;
   while(b > 0) {
      if(b & 1LL) ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      b >>= 1LL;
   }
   return ans;
}

int dfs(int u) {
   vis[u] = 1;
   int ans = 0;
   for(auto&[v, c] : t[u]) {
      if(!vis[v] && c == 0) {
         ans = ans + 1 + dfs(v);
      }
   }
   return ans;
}

void solve() {
   int n, k;
   cin >> n >> k;
   for(int i = 1; i < n; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      t[u].push_back({v, c});
      t[v].push_back({u, c});
   }
   int ans = binpow(n, k);
   for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
         ans = (ans - binpow(dfs(i) + 1, k) + MOD) % MOD;
      }
   }
   cout << ans << '\n';
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