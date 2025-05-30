#include bitsstdc++.h

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pairint, int ii;

const int inf = (int)1e18;
const int MAX = (int)1e5 + 7;
int n;
vectorint t[MAX];
int d[MAX], sz_sub[MAX], tin[MAX], tout[MAX];
int timer;

int A[MAX][32];
void dfs(int u, int p = 0) {
   tin[u] = ++timer;
   d[u] = d[p] + 1;
   sz_sub[u] = 1;
   A[u][0] = p;
   for(int i = 1; i  32; i++) {
      A[u][i] = A[ A[u][i - 1] ][i - 1];
   }
   for(int v  t[u]) if(v != p) dfs(v, u), sz_sub[u] += sz_sub[v];
   tout[u] = ++timer;
}

int get_ancestor(int u, int x) {
   int depth = d[u] - x;
   for(int i = 31; i = 0; i--) {
      if(d[ A[u][i] ] = depth) {
         u = A[u][i];
      }
   }
   return u;
}

int is_ancestor(int u, int v) {
   return tin[u] = tin[v] && tout[u] = tout[v];
}

int lca(int u, int v) {
   if(is_ancestor(u, v))
      return u;
   if(is_ancestor(v, u))
      return v;
   for(int i = 31; i = 0; i--) {
      if(A[u][i] && !is_ancestor(A[u][i], v)) {
         u = A[u][i];
      }
   }
   return A[u][0];
}

void solve() {
   cin  n;
   for(int i = 1; i  n; i++) {
      int u, v;
      cin  u  v;
      t[u].push_back(v);
      t[v].push_back(u);
   }
   timer = 0;
   dfs(1);
   int Q;
   cin  Q;
   while(Q--) {
      int a, b;
      cin  a  b;
      int u = lca(a, b);
      int dis_a = d[a] - d[u];
      int dis_b = d[b] - d[u];
      if(a == b) {
         cout  n  'n';
      } else if((dis_a + dis_b) % 2) {
         cout  0n; continue;
      } else if(d[a] == d[b]) {
         int ans = sz_sub[1] - sz_sub[get_ancestor(a, dis_a - 1)] - sz_sub[get_ancestor(b, dis_b - 1)];
         cout  ans  'n';
      } else {
          search in a
         if(dis_a  dis_b) swap(a, b), swap(dis_a, dis_b);
         int v = get_ancestor(a, d[a] - (d[a] - (dis_a + dis_b)  2));
         int ans = sz_sub[v] - sz_sub[get_ancestor(a, d[a] - d[v] - 1)];
         cout  ans  'n';
      }
   }
}

int32_t main() {
   iossync_with_stdio(false); cin.tie(0);
   int t = 1; cin  t;
   while(t--) solve();
   return 0;
}