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
int n;

void solve() {
   while(true) {
      vi a(n);
      cin >> a[0];
      if(a[0] == 0) {
         cout << '\n'; break;
      }
      for(int i = 1; i < n; i++) {
         cin >> a[i];
      }
      stack<int> st;
      int p = 0;
      for(int i = 1; i <= n; i++) {
         st.push(i);
         while(p < n && !st.empty() && st.top() == a[p]) {
            st.pop();
            p += 1;  
         }
      }
      cout << (p == n ? "Yes" : "No") << '\n';
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> n) if(n != 0) {
      solve();
   } else {
      break;
   } 
   return 0;
}