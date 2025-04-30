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

struct info {
   int x;
   int l;
   int r;
   int h;
   bool operator<(const info& other) const {
      return x < other.x;
   }
};


void solve() {
   int n;
   cin >> n;
   vector<info> a(n + 1);
   for(int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].h;
      a[i].l = a[i].r = a[i].x;
   }
   sort(a.begin(), a.end());
   int ans = 0;
   for(int i = 1; i <= n; i++) {
      if(i == 1 || a[i].x - a[i].h > a[i - 1].r) {
         ans += 1;
      } else if(i == n || a[i].x + a[i].h < a[i + 1].x){
         ans += 1;
         a[i].r = a[i].x + a[i].h;
      }
   }
   cout << ans << '\n';
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