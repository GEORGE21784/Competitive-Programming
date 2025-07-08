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

const int MAX = 1e5+7;
const int INF = 1e9;
const int MOD = 998244353;
int n;

void solve() {
   vector<string> a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   string s = "";
   string t = a[n / 2];
   for(int i = 0; i < sz(a[n / 2 - 1]) - 1; i++) {
      s += a[n / 2 - 1][i];
      if(s.back() != 'Z') {
         s.back() += 1;
         if(s < t) {
            cout << s << '\n';
            return;
         }
         s.back() -= 1;
      }
   }
   s += a[n / 2 - 1].back();
   if(s < t) {
      cout << s << '\n';
   } else {
      if(s.back() != 'Z') s.back() += 1;
      cout << s << '\n';
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> n) if(!n) {break;} else solve();
   return 0;
}