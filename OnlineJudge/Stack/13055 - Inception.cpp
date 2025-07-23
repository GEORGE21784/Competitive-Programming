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

void solve() {
   int Q;
   cin >> Q;
   stack<string> st;
   while(Q--) {
      string s;
      cin >> s;
      if(s == "Sleep") {
         string dream;
         cin >> dream;
         st.push(dream);
      } else if(s == "Test") {
         cout << (st.empty() ? "Not in a dream" : st.top()) << '\n';
      } else if(!st.empty()){
         st.pop();
      }
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(t--) {
      solve();
   }
   return 0;
}