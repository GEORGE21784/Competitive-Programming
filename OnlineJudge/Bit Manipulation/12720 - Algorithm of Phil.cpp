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
typedef vector<vi> Matrix;

const int MAX = 1e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;

int dp[MAX];
void add(int &x, int add) {
   x = (x + add) % MOD;
}

int solve() {
   string s;
   cin >> s;
   int n = sz(s);
   int m = n / 2;
   string a = s.substr(0, m), b = s.substr(m);
   reverse(b.begin(), b.end());
   string S = "";
   for(int i = 0; i < n; i++) {
      if(sz(b) > sz(a)) swap(a, b);
      if(sz(a) != sz(b)) {
         S += (a.back() == '1' ? '1' : '0');
         a.pop_back();
      } else {
         assert(sz(a) && sz(b));
         if(a.back() > b.back()) {
            S += a.back();
            a.pop_back();
         } else {
            S += b.back();
            b.pop_back();
         }
      }
   }
   reverse(S.begin(), S.end());
   int ans = 0;
   for(int i = 0; i < n; i++) if(S[i] == '1') add(ans, dp[i]);
   return ans;
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   dp[0] = 1;
   for(int i = 1; i < MAX; i++) dp[i] = (dp[i - 1] * 2) % MOD;
   int t = 1; 
   cin >> t;
   for(int i = 1; i <= t; i++) {
      cout << "Case #" << i << ": " << solve() << '\n';
   }
   return 0;
}