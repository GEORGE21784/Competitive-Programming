#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e17;
const int MAX = (int)2e3 + 7;
const int MOD = (int)1e9 + 7;
string a, b, c;
int dp[MAX][MAX];

int f(int i, int j) {
   if(i == 0 && j == 0)
      return 0;
   int &ans = dp[i][j];
   if(ans != -1)
      return ans;
   int S = i + j;
   if(i > 0 && j > 0) {
      ans = max(f(i - 1, j) + (a[i] == c[S]), f(i, j - 1) + (b[j] == c[S]));
   } else if(i > 0) {
      ans = f(i - 1, j) + (a[i] == c[i]);
   } else {
      ans = f(i, j - 1) + (b[j] == c[j]);
   }
   return ans;
}

void solve() {
   cin >> a >> b >> c;
   int n = sz(c);
   a = ' ' + a;
   b = ' ' + b;
   c = ' ' + c;
   for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) {
      dp[i][j] = -1;
   }
   cout << n - f(sz(a) - 1, sz(b) - 1) << '\n';
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