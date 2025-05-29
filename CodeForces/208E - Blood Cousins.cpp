#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5 + 7;

/* Conjunto de ideas clave para la resolucion:
   - Encontrar el ancestro x nodos por arriba del nodo u.
   - Encontrar la frecuencia de un numero x en el subarbol de u (Euler Tour).
*/

int n;
vector<int> t[MAX];
int a[MAX], vis[MAX], f[MAX], d[MAX], size_sub[MAX];
vector<int> e;
map<int, vector<int>> mp;

void dfs(int u, int p = 0) {
   d[u] = d[p] + 1;
   f[u] = sz(e);
   mp[d[u]].push_back(f[u]);
   e.push_back(d[u]);
   size_sub[u] = 1;
   
   vis[u] = true;

   for(int v : t[u]) if(v != p) {
      dfs(v, u);
      size_sub[u] += size_sub[v];
   }
}

int A[MAX][32];
void dfs2(int u, int p = 0) {
   A[u][0] = p;
   for(int k = 1; k < 32; k++) {
      A[u][k] = A[ A[u][k - 1] ][k - 1];
   }
   
   for(int v : t[u]) if(v != p) {
      dfs2(v, u);
   }
}

int get_ancestor(int u, int x) {
   int depth = d[u] - x;
   if(depth < 1) return -1;
   for(int k = 31; k >= 0; k--) {
      if(d[ A[u][k] ] >= depth) {
         u = A[u][k];
      }
   }
   return u;
}

void solve() {
   cin >> n;
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
      if(a[i]) {
         t[i].push_back(a[i]);
         t[a[i]].push_back(i);
      }
   }
   memset(A, 0, sizeof(A));
   for(int i = 1; i <= n; i++) if((!a[i]) && (!vis[i])) {
      dfs(i);
      dfs2(i);
   }
   int Q;
   cin >> Q;
   while(Q--) {
      int v, p;
      cin >> v >> p;
      int u = get_ancestor(v, p);
      if(u == -1) {
         cout << "0 ";
         continue;
      } 
      int left = f[u];
      int right = left + size_sub[u] - 1;
      vector<int> &vec = mp[ d[v] ];
      int l = lower_bound(vec.begin(), vec.end(), left) - vec.begin();
      int r = upper_bound(vec.begin(), vec.end(), right) - vec.begin();
      r -= 1;
      cout << max(r - l, 0LL) << ' ';
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; //cin >> t;
   while(t--) solve();
   return 0;
}