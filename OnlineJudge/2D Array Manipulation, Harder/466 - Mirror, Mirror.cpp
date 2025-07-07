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
typedef vector<string> Matrix;

const int MAX = 1e6+7;
const int INF = 1e9;
const int MOD = 998244353;
int n;

Matrix rotation(Matrix a) {
   Matrix b = a;
   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      b[i][j] = a[n - 1 - j][i];
   }
   return b;
}

Matrix reflection(Matrix a) {
   Matrix b = a;
   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      b[i][j] = a[n - i - 1][j];
   }
   return b;
}

void solve() {
   Matrix a(n), b(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
   }   
    
   if(a == b) {
      cout << "preserved.\n";
      return;
   }

   Matrix c = a;
   for(int i = 1; i <= 3; i++) {
      c = rotation(c);
      if(c == b) {
         cout << "rotated " << i*90 << " degrees.\n";
         return;
      }
   }
   
   if(reflection(a) == b) {
      cout << "reflected vertically.\n";
      return;
   }

   c = reflection(a);
   for(int i = 1; i <= 3; i++) {
      c = rotation(c);
      if(c == b) {
         cout << "reflected vertically and rotated " << i*90 << " degrees.\n";
         return;
      }
   }

   cout << "improperly transformed.\n";
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   // int t = 1;
   // cin >> t;
   for(int i = 1; cin >> n; i++) {
      cout << "Pattern " << i << " was ";
      solve();
   }
   return 0;
}