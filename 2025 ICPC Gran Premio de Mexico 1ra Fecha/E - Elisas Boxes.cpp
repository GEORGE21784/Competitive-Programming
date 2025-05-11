#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)101;
const int MOD = (int)1e9 + 7;

void solve() {
   int n, x;
   cin >> n >> x;
   int p = -1;
   for(int i = 1; i <= n; i++) {
      int nx; cin >> nx;
      if(nx >= x && p == -1) {
         p = i;
      }
   }
   cout << p << '\n';
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