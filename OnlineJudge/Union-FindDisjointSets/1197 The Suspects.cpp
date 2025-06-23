/* author: gerogeVT
*/
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define LSOne(S) ((S) & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 2e5+7;
const int INF = 1e9;
const int MOD = 1e9+7;

class UnionFind {
    private:
        vi rank, p, setSize;
    public:
        UnionFind(int n) {
            p.assign(n, 0); for(int i = 0; i < n; i++) p[i] = i;
            rank.assign(n, 0);
            setSize.assign(n, 1);
        }
        
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }

        void unionSet(int i, int j) {
            if(isSameSet(i, j)) return;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if(rank[x] == rank[y]) rank[y] += 1;
            setSize[y] += setSize[x];
        }

};

int n, m;

void solve() {
    UnionFind dsu(n);
    while(m--) {
        int k;
        cin >> k;
        int lst = -1;
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if(lst != -1) {
                dsu.unionSet(lst, x);
            }
            lst = x;
        }
    }
    cout << dsu.sizeOfSet(0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while(cin >> n >> m) {
        if(n + m != 0) solve();
    } 
    return 0;
}
