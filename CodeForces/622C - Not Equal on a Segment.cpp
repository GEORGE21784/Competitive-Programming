#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)2e5 + 7;

void solve() {
   int n, q; 
   cin >> n >> q;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   vector<int> b(n + 1 , 1);
   for(int i = 2; i <= n; i++) {
      if(a[i] == a[i - 1]) {
         b[i] = b[i - 1] + 1;
      }
   }
   while(q--) {
      int x, y, u;
      cin >> x >> y >> u;
      if(a[x] != u) {
         cout << x << '\n';
         continue;
      }
      int l = x, r = y + 1;
      while(r - l > 1) {
         int md = l + (r - l) / 2;
         if(b[md] - b[x] == md - x) {
            l = md;
         } else {
            r = md;
         }
      }
      cout << (l < y ? l + 1 : -1) << '\n';
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