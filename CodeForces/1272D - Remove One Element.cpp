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

void solve() {
   int n;
   cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   vector<int> b(n + 1, 1);
   for(int i = 2; i <= n; i++) {
      if(a[i] > a[i - 1]) {
         b[i] = b[i - 1] + 1;
      }
   }
   int ans = *max_element(b.begin(), b.end());
   for(int i = 1; i < n; i++) {
      if(a[i + 1] <= a[i]) {
         int S = 0;
         int l = 0, r = i;
         while(r - l > 1) {
            int md = (l + r) / 2;
            if(i - md == b[i] - b[md]) {
               r = md;
            } else {
               l = md;
            }
         } 
         S += (i - r + 1);
         l = i + 1, r = n + 1;
         while(r - l > 1) {
            int md = (l + r) / 2;
            if(md - (i + 1) == b[md] - b[i + 1]) {
               l = md;
            } else {
               r = md;
            }
         } 
         S += (l - i);
         if(i + 1 <= n && a[i + 1] > a[i - 1])
            ans = max(ans, S - 1);
         if(i + 2 <= n && a[i + 2] > a[i]) 
            ans = max(ans, S - 1);
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