#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e3 + 7;

class UnionFind {
   private:
      vector<int> p, rank;
   
   public:
      UnionFind(int N) {
         p.assign(N + 1, 0); iota(p.begin(), p.end(), 0LL);
         rank.assign(N + 1, 0);
      }  

      int findSet(int i) { return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
      bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

      void unionSet(int i, int j) {
         if(isSameSet(i, j)) return;
         int x = findSet(i), y = findSet(j);
         if(rank[x] > rank[y]) swap(x, y);
         p[x] = y;
         if(rank[x] == rank[y]) ++rank[y];
      }

};

vector<int> t[MAX];
int vis[MAX];
int d[MAX], parent[MAX];
int used[MAX][MAX];

void dfs(int u, int p = 0) {
   parent[u] = p;
   d[u] = d[p] + 1;
   vis[u] = 1;
   for(int v : t[u]) if(!vis[v]) {
      dfs(v, u);
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
   for(int i = 1; i <= n; i++) if(!vis[i]) {
      dfs(i);
   }
   UnionFind dsu(n + 1);
   vector<ii> ans1;
   for(int i = 1; i <= n; i++) {
      bool par = false;
      for(int v : t[i]) {
         dsu.unionSet(i, v);
         if(!used[i][v]) {
            if(d[v] < d[i]) {
               if(!par) par = !par;
               else {
                  ans1.push_back({i, v});
                  used[i][v] = used[v][i] = 1;
               }
            }
            if(d[v] == d[i]) {
               ans1.push_back({i, v});
               used[i][v] = used[v][i] = 1;
            }
         }
      }
   }
   vector<ii> ans2;
   for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
      if(!dsu.isSameSet(i, j)) {
         ans2.push_back({dsu.findSet(i), dsu.findSet(j)});
         dsu.unionSet(i, j);
      }
   }
   cout << sz(ans1) << '\n';
   for(int i = 0; i < sz(ans1); i++) cout << ans1[i].fi << ' ' << ans1[i].se << ' ' << ans2[i].fi << ' ' << ans2[i].se << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; // cin >> t;
   while(t--) solve();
   return 0;
}