// gerogeVT
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int MAX = (int)1e5 + 7;
const int inf = (int)1e18 + 7;

void solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vector<int> h(n);
   int p = 0;
   h[0] = 0;
   for(int i = 1; i < n; i++) {
      int j = i + 1;
      h[i] = h[p] + 1;
      while(j < n && a[j] > a[j - 1]) {
         h[j] = h[p] + 1;
         j += 1;
      }
      j -= 1;
      p += 1;
      i = j;
   }
   cout << *max_element(h.begin(), h.end()) << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie();
   int t = 1; cin >> t;
   while(t--) solve();
   return 0;
}