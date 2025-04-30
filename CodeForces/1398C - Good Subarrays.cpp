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
   string s;
   cin >> n >> s;
   s = ' ' + s;
   int ans = 0, S = 0;
   map<int, int> mp;
   mp[0] = 1;
   for(int i = 1; i <= n; i++) {
      S += s[i] - '0';
      ans += mp[S - i];
      mp[S - i] += 1;
   }
   cout << ans << '\n';
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