#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5+7;
const int MOD = (int)1e9 + 7;

void solve() {
   int n;
   cin >> n;
   vector<vector<int>> a(n, vector<int>(n));
   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      cin >> a[i][j];
   }
   
   auto rot = [&]() {
      vector<vector<int>> b = a;
      for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
         b[i][j] = a[j][n - i - 1];
      }
      a = b;
   };
   
   auto esp = [&]() {
      vector<vector<int>> b = a;
      for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
         b[i][j] = a[j][i];
      }
      a = b;
   };
   
   auto f = [&](vector<int>& b) -> int {
      int sm = 0, mx = 0;
      for(int i = 0; i < n * n; i++) {
         sm = max(sm + b[i], b[i]);
         mx = max(mx, sm);
      }
      return mx;
   };

   auto calc = [&]() -> int {
      vector<int> b;
      for(int k = 0; k < n / 2; k++) {
         for(int i = 0; i < n - k*2 - 1; i++) {
            b.push_back(a[k + i][k]);
         }
         for(int i = 0; i < n - k*2 - 1; i++) {
            b.push_back(a[n - k - 1][k + i]);
         }
         for(int i = 0; i < n - k*2 - 1; i++) {
            b.push_back(a[n - k - 1 - i][n - k - 1]);
         }
         for(int i = 0; i < n - k*2 - 1; i++) {
            b.push_back(a[k][n - k - 1 - i]);
         }
      }
      if(n % 2) b.push_back(a[n / 2][n / 2]);
      return f(b);
   };
   
   int ans = 0;
   for(int i = 0; i < 4; i++) {
      ans = max(ans, calc());
      rot();
   }
   
   esp();
   
   for(int i = 0; i < 4; i++) {
      ans = max(ans, calc());
      rot();
   }

   cout << ans << '\n';
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