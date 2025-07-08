/* author: gerogeVT */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double
#define LSOne(S) ((S) & (-S))

using namespace __gnu_pbds;
using namespace std;
template<typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 1e5+7;
const int INF = 1e9;
const int MOD = 998244353;
int n;

void solve() {
   vi a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] -= 1;
   }   
   ordered_set<int> os;
   vi pos(n);
   for(int i = 0; i < n; i++) {
      pos[a[i]] = i;
      os.insert(i);
   }
   int cnt = 0;
   for(int i = 0; i < n; i++) {
      cnt += os.order_of_key(pos[i]);
      os.erase(pos[i]);
   }
   cout << (cnt % 2 ? "Marcelo" : "Carlos") << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> n) if(!n) {break;} else solve();
   return 0;
}