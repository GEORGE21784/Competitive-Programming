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

/*
Suppose we want to calculate the number of inversions for an array [a, a+1, ..., b-1, b].
The key idea to solve this task is as follows:
- Let u the first half of the array and v the other half both sorted in non-decreasing order.
- It is easy to notice that the number of inversions of v does not change, only for u.
- To count the number of inversions between u and v is done with two pointers (since both arrays are sorted) in O(|u| + |v|).
MergeSort is the key
*/

int n, cnt;
int a[MAX];

int count(vi& a, vi& b) {
   int ans = 0;
   int n = sz(a);
   int m = sz(b);
   for(int i = 0, l = 0; i < n; i++) {
      while(l < m && b[l] < a[i]) {
         l += 1;
      }
      ans += l;
   }
   return ans;
}

vi mergeSort(int l, int r) {
   assert(l <= r);
   if(l == r) return {a[l]};
   int mid = (l + r) / 2;
   vi a = mergeSort(l, mid);
   vi b = mergeSort(mid + 1, r);
   cnt += count(a, b);
   vi ans;
   int i = 0, j = 0;
   for(int _ = 0; _ < sz(a) + sz(b); _++) {
      if(i < sz(a) && (j == sz(b) || a[i] <= b[j])) {
         ans.push_back(a[i++]);
      } else {
         ans.push_back(b[j++]);
      }
   }
   return ans;
}

void solve() {
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   cnt = 0;
   vi v = mergeSort(0, n - 1);
   cout << cnt << '\n';
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> n) if(!n) {break;} else solve();
   return 0;
}