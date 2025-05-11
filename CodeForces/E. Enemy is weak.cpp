#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5 + 7;

class SegmentTree {
   private:
      int n;
      vector<int> st, A;

      int lf(int p) {return p << 1LL;}
      int rt(int p) {return (p << 1LL) + 1;}

      void update(int p, int l, int r, int x) {
         if(l == r) {
            st[p] = 1;
            return;
         }
         int m = (l + r) / 2;
         if(x <= m) {
            update(lf(p), l, m, x);
         } else {
            update(rt(p), m+1, r, x);
         }
         st[p] = st[lf(p)] + st[rt(p)];
      }

      int query(int p, int l, int r, int L, int R) {
         if(r < L || l > R) return 0;
         if(l >= L && r <= R) return st[p];
         int m = (l + r) / 2;
         return query(lf(p), l, m, L, R) + query(rt(p), m+1, r, L, R);
      }

   public:
      SegmentTree(int S) : n(S), st(n*4) {
         A = vector<int>(S+1);
      }

      void update(int x) {update(1, 1, n, x);}
      int query(int l, int r) {return query(1, 1, n, l, r);}
};

void solve() {
   int n;
   cin >> n;
   set<ii> st;
   for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      st.insert({x, i});
   }
   
   vector<int> a(n + 1);
   int x = 1;
   while(sz(st)) {
      ii u = *st.begin();
      st.erase(u);
      a[u.se] = x++;
   }

   SegmentTree ST(n);
   
   int ans = 0;
   for(int i = 1; i < n; i++) {
      if(i > 1) {
         int may = ST.query(a[i] + 1, n);
         int men = (n - i) - (n - a[i] - may);
         ans += may * men;
      }
      ST.update(a[i]);
   }

   cout << ans << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; // cin >> t;
   while(t--) solve();
   return 0;
}