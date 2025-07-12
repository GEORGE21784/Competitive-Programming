/* author: gerogeVT */
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double
#define LSOne(S) ((S) & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 1e6+7;
const int INF = 1e9;
const int MOD = 998244353;

void solve() {
   int n, q;
   cin >> n >> q;
   vi a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vi ans(230);
   for(int x = 0; x < 230; x++) {
      for(int i = 0; i < n; i++) {
         ans[x] = max(ans[x], (x & a[i]));
      }
   }
   while(q--) {
      int a;
      cin >> a;
      cout << ans[a] << '\n'; 
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