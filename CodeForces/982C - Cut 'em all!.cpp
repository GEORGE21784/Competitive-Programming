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
vector<int> t[MAX];
int d[MAX], s[MAX];

void dfs(int u, int p = 0) {
   d[u] = d[p] + 1;
   s[u] = 1;
   for(int v : t[u]) if(v != p) {
      dfs(v, u);
      s[u] += s[v];
   }
}


void solve() {
   int n;
   cin >> n;
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      t[u].push_back(v);
      t[v].push_back(u);
   }
   if(n % 2) {
      cout << "-1\n";
      return;
   }
   dfs(1);
   int ans = 0;
   for(int i = 1; i <= n; i++) {
      for(int v : t[i]) {
         if(d[v] < d[i]) {
            ans += (s[i] % 2 == 0);
         }
      }
   }
   cout << ans << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; // cin >> t;
   while(t--) solve();
   return 0;
}