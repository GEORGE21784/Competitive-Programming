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
const int MOD = (int)1e9 + 7;

void solve() {
   int n;
   cin >> n;
   vector<int> dp(4);
   dp[0] = 1;
   for(int i = 1; i <= n; i++) {
      vector<int> ndp(4);
      int S = accumulate(dp.begin(), dp.end(), 0LL) % MOD;
      for(int j = 0; j < 4; j++) {
         ndp[j] = (S - dp[j] + MOD) % MOD;
      }
      swap(ndp, dp);
   }
   cout << dp[0] << '\n';
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