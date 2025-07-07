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
int n, m, Q;

void solve() {
   cin >> n >> m >> Q;
   Matrix input;
   // (team, problem) -> AC? 
   Matrix g(m + 1, vi(n));
   // winner[x] winner of problem x
   vi winner(n, -1);
   for(int i = 0; i < Q; i++) {
      int timer, team; string a, b;
      cin >> timer >> team >> a >> b;
      int pro = a[0] - 'A';
      int ver = (b == "Yes");
      input.push_back({timer, team});
      if(ver) {
         if(!g[team][pro]) {
            winner[pro] = i;
         }
         g[team][pro] = 1;
      }
   }
   for(int i = 0; i < n; i++) {
      cout << char(i + 'A') << ' ';
      int w = winner[i]; 
      if(w != -1) {
         cout << input[w][0] <<  ' ' << input[w][1] << '\n';
      } else {
         cout << "- -\n";
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