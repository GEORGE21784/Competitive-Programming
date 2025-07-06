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

const int MAX = 1e6+7;
const int INF = 1e9;
const int MOD = 998244353;

void solve() {
   int x;
   while(cin >> x) {
      if(!x) break;
      int a = 0, b = 0;
      for(int i = 0; i < 31; i++) {
         int k = (1ll << i); 
         if(x & k) {
            if(a <= b) a += k; 
            else b += k;
         }
      }
      cout << a << ' ' << b << '\n';
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(t--) solve();
   return 0;
}