#include <bits/stdc++.h>

// #define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = (int)1e9;
const int MAX = (int)1e5 + 7;
int n, m, Q;
vi t[MAX];
vi st[MAX][20], S[MAX];
int d[MAX];

vi merge(vi S1, vi S2) {
   for(auto x : S2) if(find(S1.begin(), S1.end(), x) == S1.end()) S1.push_back(x);
   sort(S1.begin(), S1.end());
   while(sz(S1) > 10) S1.pop_back();
   return S1;
}

int timer;
int tin[MAX], tout[MAX];
int A[MAX][20];
void dfs(int u, int p = 0) {
   d[u] = d[p] + 1;
   
   tin[u] = ++timer;
   A[u][0] = p;
   st[u][0] = merge(S[u], S[p]);
   for(int i = 1; i < 20; i++) {
      A[u][i] = A[ A[u][i - 1] ][i - 1];
      st[u][i] = merge(st[u][i - 1], st[A[u][i - 1]][i - 1]);
   }
   for(int v : t[u]) if(v != p) dfs(v, u);
   tout[u] = ++timer;
}

int is_ancestor(int u, int v) {
   return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
   if(is_ancestor(u, v))
      return u;
   if(is_ancestor(v, u))
      return v;
   for(int i = 19; i >= 0; i--) {
      if(A[u][i] && !is_ancestor(A[u][i], v)) {
         u = A[u][i];
      }
   }
   return A[u][0];
}

void print(vi st, int k) {
   int mn = min(sz(st), k);
   auto it = st.begin();
   cout << mn << ' ';
   while(mn--) {
      cout << *it << ' ';
      it++;
   }
   cout << '\n';
}

vi get_path(int u, int top) {
   vi ans = S[u];
   int depth = d[top];
   for(int i = 19; i >= 0; i--) {
      if(d[A[u][i]] >= depth) {
         ans = merge(ans, st[u][i]);
         u = A[u][i];
      }
   }
   return ans;
}

void query(int u, int v, int a) {
   if(u == v) {
      print(S[u], a);
   } else {
      int LCA = lca(u, v);
      print(merge(get_path(u, LCA), get_path(v, LCA)), a);
   }
}

void solve() {
   cin >> n >> m >> Q;
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      t[u].push_back(v);
      t[v].push_back(u);
   }   
   for(int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      S[x].push_back(i);
   }
   for(int i = 1; i <= n; i++) {
      sort(S[i].begin(), S[i].end());
      while(sz(S[i]) > 10) S[i].pop_back();
   }
   timer = 0;
   dfs(1);
   while(Q--) {
      int u, v, a;
      cin >> u >> v >> a;
      query(u, v, a); 
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; //cin >> t;
   while(t--) solve();
   return 0;
}