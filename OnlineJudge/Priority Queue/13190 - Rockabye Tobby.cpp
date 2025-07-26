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

const int MAX = 2e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
   int n, k;
   cin >> n >> k;
   vector<string> a(n);
   vi b(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
   }
   priority_queue<ii, vector<ii>, greater<ii>> q;
   for(int i = 0; i < n; i++) {
      q.push({b[i], i});
   }
   for(int i = 0; i < k; i++) {
      auto [w, j] = q.top();
      q.pop();
      cout << w << ' ' << a[j] << '\n';
      q.push({w + b[j], j});
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   cin >> t;
   while(t--) {
      solve();
   }
   return 0;
}