/* author: gerogeVT */
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define LSOne(S) ((S) & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> Matrix;
typedef pair<int, ii> node;

const int MAX = 2e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;
int n;

void solve() {
   vi a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());

   for(int k = 1; k < n; k++) {
      vi b(n);
      for(int i = 0; i < n; i++) {
         cin >> b[i];
      }
      sort(b.begin(), b.end());

      vi newA;
      set<ii> vis;
      priority_queue<node, vector<node>, greater<node>> q;
      vis.insert({0, 0});
      q.push({a[0] + b[0], {0, 0}});

      for(int i = 0; i < n; i++) {
         int sum = q.top().fi;
         int u = q.top().se.fi, v = q.top().se.se;
         q.pop();
         newA.push_back(sum);
         if(u + 1 < n && !vis.count({u + 1, v})) {
            q.push({sum - a[u] + a[u + 1], {u + 1, v}});
            vis.insert({u + 1, v});
         }
         if(v + 1 < n && !vis.count({u, v + 1})) {
            q.push({sum - b[v] + b[v + 1], {u, v + 1}});
            vis.insert({u, v + 1});
         }
      }

      a = newA;
   }

   for(int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> n) {
      solve();
   }
   return 0;
}