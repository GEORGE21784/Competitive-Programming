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

const int MAX = 1e6+7;
const int INF = 1e9;
const int MOD = 998244353;
int n, k;

void solve() {
   cin >> n >> k;
   cout << (k ^ (k >> 1LL)) << '\n';
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