/* author: gerogeVT */
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define LSOne(S) ((S) & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> Matrix;

const int MAX = 2e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;
int Q;

void solve() {
   queue<int> q;
   stack<int> st;
   priority_queue<int> pq;
   vi fail(3); //(failQueue, failStack, failPQ)
   
   while(Q--) {
      int type, x;
      cin >> type >> x;
      if(type == 1) {
         q.push(x);
         st.push(x);
         pq.push(x);
      } else {
         fail[0] |= (q.empty() || q.front() != x);
         if(sz(q)) q.pop();
         fail[1] |= (st.empty() || st.top() != x);
         if(sz(st)) st.pop();
         fail[2] |= (pq.empty() || pq.top() != x);
         if(sz(pq)) pq.pop();
      }
   }

   int cnt = 3 - accumulate(fail.begin(), fail.end(), 0);
   if(cnt == 1) {
      for(int i = 0; i < 3; i++) {
         if(!fail[i]) {
            if(i == 0) {
               cout << "queue\n";
            } else if(i == 1) {
               cout << "stack\n";
            } else {
               cout << "priority queue\n";
            }
         }
      }
   } else if(cnt == 0) {
      cout << "impossible\n";
   } else {
      cout << "not sure\n";
   }
}

int32_t main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int t = 1; 
   // cin >> t;
   while(cin >> Q) {
      solve();
   }
   return 0;
}