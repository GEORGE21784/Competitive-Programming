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
typedef vector<string> MatrixS;

const int MAX = 1e6+7;
const int INF = 1e9;
const int MOD = 998244353;
int n, m;

void solve() {
   MatrixS a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   MatrixS b(m);
   for(int i = 0; i < m; i++) {
      cin >> b[i];
   }
   int x = -1, y;
   vector<ii> moves;
   for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) {
      if(b[i][j] == '*') {
         if(x == -1) {
            x = i, y = j;
         }
         moves.push_back({i - x, j - y});
      }
   }

   Matrix visited;
   auto isValid = [&](int i, int j) -> bool {
      return i >= 0 && i < n && j >= 0 && j < n && a[i][j] == '*' && !visited[i][j];
   };

   auto checkOther = [&]() -> bool {
      for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
         if(!visited[i][j] && a[i][j] == '*') {
            bool fail = false;
            for(auto&[pi, pj] : moves) {
               int di = i + pi;
               int dj = j + pj;
               if(!isValid(di, dj)) {fail = 1; break;}
               visited[di][dj] = 1;
            }
            if(fail) continue;
            return true;
         }
      }
      return false;
   };

   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      if(a[i][j] == '*') {
         visited.assign(n, vi(n));
         bool fail = false;
         for(auto&[pi, pj] : moves) {
            int di = i + pi;
            int dj = j + pj;
            if(!isValid(di, dj)) {fail = 1; break;}
            visited[di][dj] = 1;
         }
         if(fail) continue;
         if(checkOther()) {
            cout << "1\n";
            return;
         }
      }
   }
   cout << "0\n";
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1;
   // cin >> t;
   while(cin >> n >> m) {
      if(n + m == 0) break;
      solve();
   }
   return 0;
}