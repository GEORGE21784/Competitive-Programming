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

class SegmentTree {
   private:
      int n;
      vi st, A;
   public:
      SegmentTree(const vi &a) {
         A = a;
         n = sz(A);
         st.assign(n * 4, INF);
         init(1, 0, n - 1);
      }

      int le(int x) {return x * 2;}
      int ri(int x) {return x * 2 + 1;}

      void init(int u, int l, int r) {
         if(l == r) {
            st[u] = A[l];
            return;
         }
         int mid = (l + r) / 2;
         init(le(u), l, mid);
         init(ri(u), mid + 1, r);
         st[u] = min(st[le(u)], st[ri(u)]);
      }
      
      int query(int u, int l, int r, int ll, int rr) {
         if(l > rr || r < ll) return INF;
         if(l >= ll && r <= rr) return st[u];
         int mid = (l + r) / 2;
         return min(query(le(u), l, mid, ll, rr), query(ri(u), mid + 1, r, ll, rr));
      }

      void update(int u, int l, int r, int x, int v) {
         if(l == r) {
            st[u] = v;
            return;
         }
         int mid = (l + r) / 2;
         if(x <= mid) {
            update(le(u), l, mid, x, v);
         } else {
            update(ri(u), mid + 1, r, x, v);
         }
         st[u] = min(st[le(u)], st[ri(u)]);
      }

      int query(int l, int r) {return query(1, 0, n - 1, l, r);}
      void update(int pos, int val) {update(1, 0, n - 1, pos, val);}
};

void solve() {
   int n, Q;
   cin >> n >> Q;
   vi a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   SegmentTree st(a);
   while(Q--) {
      int o, x, y;
      cin >> o >> x >> y;
      if(o == 1) {
         st.update(x - 1, y);
      } else {
         cout << st.query(x - 1, y - 1) << '\n'; 
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