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
vector<int> g[MAX];
map<int, vector<int>> mp;
int c[MAX];
int d[MAX];
int fs[MAX];
vector<int> a;

void dfs(int u, int p = -1) {
   fs[u] = sz(a);
   a.push_back(u);
   d[u] = 1;
   for(int v : g[u]) if(v != p) {
      dfs(v, u);
      d[u] += d[v];
   }
}

void solve() {
   int n, Q;
   cin >> n >> Q;
   for(int i = 1; i <= n; i++) {
      cin >> c[i];
   }
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dfs(1);
   for(int i = 0; i < n; i++) {
      mp[ c[ a[i] ] ].push_back(i);
   }
   while(Q--) {
      int u, x;
      cin >> u >> x;
      vector<int> &b = mp[x];
      int left = fs[u], right = left + d[u] - 1;
      int l = -1, r = sz(b);
      while(r - l > 1) {
         int md = l + (r - l) / 2;
         if(b[md] <= right) {
            l = md;
         } else {
            r = md;
         }
      }
      int ans = r;
      l = -1, r = sz(b);
      while(r - l > 1) {
         int md = l + (r - l) / 2;
         if(b[md] >= left) {
            r = md;
         } else {
            l = md;
         }
      }
      ans = max(ans - r, 0LL);
      cout << ans << '\n';
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