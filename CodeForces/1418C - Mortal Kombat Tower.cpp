#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e17;
const int MAX = (int)2e5 + 7;
const int MOD = (int)1e9 + 7;

void solve() {
   int n; 
   cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   
   vector<vector<int>> dp(n + 1, vector<int>(2, 0)), f(n + 1, vector<int>(2, 1));
   for(int i = 1; i <= n; i++) dp[i][0] = inf, dp[i][1] = -inf;

   f[1][1] = f[0][0] = 0;
   dp[1][0] = a[1];
   dp[1][1] = dp[0][0] = dp[0][1] = 0;

   int S = a[1];
   for(int i = 2; i <= n; i++) {
      S += a[i];
      // min sum takeing only one
      if(f[i - 1][1]) {
         dp[i][0] = S - dp[i - 1][1];
      }
      // min sum takeing two
      if(f[i - 2][1]) {
         dp[i][0] = min(dp[i][0], S - dp[i - 2][1]);
      }
      // max sum taking only one
      if(f[i - 1][0]) {
         dp[i][1] = S - dp[i - 1][0];
      }
      // max sum taking teo
      if(f[i - 2][0]) {
         dp[i][1] = max(dp[i][1], S - dp[i - 2][0]);
      }
   }
   cout << min(dp[n][0], S - dp[n][1]) << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int t = 1;
   cin >> t;
   while(t--) {
      solve();
   }
   return 0;
}