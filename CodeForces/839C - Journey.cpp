// gerogeVT
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int MAX = (int)1e5 + 7;
const int inf = (int)1e18 + 7;

vector<int> g[MAX];

ld dfs(int u, int p = -1) {
   ld ans = 0.0;
   for(int v : g[u]) if(v != p) {
      ans += dfs(v, u);
   }
   if(sz(g[u]) != 1) ans /= (u == 1 ? sz(g[u]) : (sz(g[u]) - 1));
   if(u == 1 || sz(g[u]) > 1) ans += 1.0;
   return ans;
}

void solve() {
   int n; 
   cin >> n;
   if(n == 1) {
      cout << "0.0000000";
      return;
   }
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);      
      g[v].push_back(u);      
   }
   cout << fixed << setprecision(8) << dfs(1) << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie();
   int t = 1; //cin >> t;
   while(t--) solve();
   return 0;
}