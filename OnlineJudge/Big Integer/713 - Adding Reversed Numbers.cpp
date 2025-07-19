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

const int MAX = 2e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;

void f(string &s) {
   while(sz(s) > 1 && s.back() == '0') {
      s.pop_back();
   }
   reverse(s.begin(), s.end());
}

void solve() {
   string a, b;
   cin >> a >> b;
   f(a);
   f(b);
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   string ans = "";
   int res = 0;
   for(int i = 0; i < max(sz(a), sz(b)); i++) {
      int x = (i < sz(a) ? a[i] - '0' : 0);
      int y = (i < sz(b) ? b[i] - '0' : 0);
      int S = x + y + res;
      ans += (S % 10) + '0';
      res = S / 10;
   }
   if(res) ans += to_string(res);
   reverse(ans.begin(), ans.end());
   f(ans);
   cout << ans << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   cin >> t;
   while(t--) {
      solve();
   }
   return 0;
}