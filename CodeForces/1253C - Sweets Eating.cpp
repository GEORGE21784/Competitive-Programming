#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)2e5 + 7;
const int MOD = (int)1e9 + 7;

void solve() {
   int n, m;
   cin >> n >> m;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) {  
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   vector<int> f(n + 1), dp(n + 1);
   for(int i = 1; i <= n; i++) {
      f[i % m] += a[i];
      dp[i] = dp[i - 1] + f[i % m];
      cout << dp[i] << ' ';
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