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

void row(Matrix &a, int i, int j) {
   swap(a[i], a[j]);
}

void col(Matrix &a, int i, int j) {
   for(int f = 0; f < n; f++) {
      swap(a[f][i], a[f][j]);
   }
}

void inc(Matrix &a, int add) {
   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      a[i][j] = '0' + (a[i][j] - '0' + add + 10) % 10; 
   }
}

void transpose(Matrix &a) {
   Matrix b = a;
   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
      b[i][j] = a[j][i];
   }
   a = b;
}

void solve() {
   cin >> n;
   Matrix a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int Q;
   cin >> Q;
   while(Q--) {
      int i, j;
      string s;
      cin >> s;
      if(s == "transpose") {
         transpose(a);
      } else if(s == "inc") {
         inc(a, 1);
      } else if(s == "dec") {
         inc(a, -1);
      } else {
         cin >> i >> j;
         i -= 1, j -= 1;
         if(s == "row") {
            row(a, i, j);
         } else {
            col(a, i, j);
         }
      }
   }
   for(int i = 0; i < n; i++) {
      cout << a[i] << '\n';
   } cout << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1;
   cin >> t;
   for(int i = 1; i <= t; i++) {
      cout << "Case #" << i << '\n';
      solve();
   }
   return 0;
}