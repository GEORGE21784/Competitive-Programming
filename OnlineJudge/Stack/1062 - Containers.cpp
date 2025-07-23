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
string s;

int solve() {
   vector<stack<char>> st(26);
   int cur = 0, ans = 0;
   for(char c : s) {
      bool find = false;
      for(int i = 0; i < cur; i++) {
         if(c <= st[i].top()) {
            st[i].push(c);
            find ^= 1;
            break;
         }
      }
      if(!find && cur < 26) {
         st[cur++].push(c);
         ans += 1;
      }
   }
   ans = min(ans, sz(set<char>(s.begin(), s.end())));
   return ans;
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   for(int i = 1; cin >> s; i++) {
      if(s == "end") break;
      cout << "Case " << i << ": " << solve() << '\n';
   }
   return 0;
}