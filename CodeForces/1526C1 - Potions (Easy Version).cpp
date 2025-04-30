#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)2e5 + 7;
const int MOD = (int)998244353;

void solve() {
   int n;
   cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -inf));
   for(int i = 0; i <= n; i++) dp[i][0] = 0;
   for(int i = 1; i <= n; i++) {
      for(int k = 1; k <= i; k++) {
         if(dp[i - 1][k - 1] >= 0) {
            if(dp[i - 1][k - 1] + a[i] >= 0) {
               dp[i][k] = dp[i - 1][k - 1] + a[i];
            }
            if(dp[i - 1][k] >= 0) {
               dp[i][k] = max(dp[i][k], dp[i - 1][k]);
            }
         }
      }
   }
   for(int k = n; k >= 0; k--) {
      if(dp[n][k] >= 0) {
         cout << k << '\n';
         break;
      }
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