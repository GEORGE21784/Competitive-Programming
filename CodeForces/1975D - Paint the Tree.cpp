// gerogeVT
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int MAX = (int)2e5 + 7;
const int inf = (int)1e18 + 7;
int n, a, b, x;
vector<int> t[MAX], path, w;
int get(int u, int p = -1, int cnt = 0) {
   path.push_back(u);
   if(u == a) {
      w = path;
      return cnt;
   }
   int ans = inf;
   for(int v : t[u]) if(v != p) {
      ans = min(ans, get(v, u, cnt + 1));
   }
   path.pop_back();
   return ans;
}

int dfs(int u, int p = -1, int cnt = 0) {
   int ans = 0;
   for(int v : t[u]) if(v != p) {
      ans = max(ans, dfs(v, u, cnt + 1));
   }
   if(sz(t[u]) == 1) ans = max(ans, cnt);
   return ans;
}

void solve() {
   cin >> n >> a >> b;
   for(int i = 1; i <= n; i++) t[i].clear(); w.clear();
   path.clear();
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      t[u].push_back(v);
      t[v].push_back(u);
   }
   int d = get(b);
   int m = (d + 1) / 2;
   int N = sz(w);
   x = w[N / 2];
   cout << 2 * (n - 1) + m - dfs(x) << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie();
   int t = 1; cin >> t;
   while(t--) solve();
   return 0;
}