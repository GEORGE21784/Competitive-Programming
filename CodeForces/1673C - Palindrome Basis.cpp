#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e17;
const int MAX = (int)4e4 + 7;
const int MOD = (int)1e9 + 7;

int dp[MAX];

bool isPal(int N) {
   string s = to_string(N);
   int n = sz(s);
   for(int i = 0; i < n; i++) 
      if(s[i] != s[n - i - 1]) 
         return false;
   return true;
}

void solve() {
   vector<int> p;
   for(int i = 1; i < MAX; i++) if(isPal(i)) {
      p.push_back(i);
   }
   dp[0] = 1;
   for(int x : p) {
      for(int i = 0; i < MAX; i++) {
         if(i - x >= 0) {
            dp[i] += dp[i - x];
            dp[i] %= MOD;
         }
      }
   }
   int tt;
   cin >> tt;
   while(tt--) {
      int n;
      cin >> n;
      cout << dp[n] << '\n';
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