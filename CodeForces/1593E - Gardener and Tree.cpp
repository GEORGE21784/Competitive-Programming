// gerogeVT
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int MAX = (int)4e5 + 7;
const int inf = (int)1e18 + 7;
int n, k;
set<int> t[MAX];
int vis[MAX];

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) t[i].clear(), vis[i] = 0;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t[u].insert(v);
        t[v].insert(u);
    }
    vector<int> leafs;
    for(int i = 1; i <= n; i++) if(sz(t[i]) <= 1) {
        leafs.push_back(i);
    }
    int cnt = n;
    for(int _ = 0; _  < k && sz(leafs); _++) {
        vector<int> new_leafs;
        while(sz(leafs)) {
            int u = leafs.back();
            leafs.pop_back();
            if(sz(t[u])) {
                int v = *t[u].begin();
                t[v].erase(t[v].find(u));
                if(!vis[v] && sz(t[v]) <= 1) {
                    vis[v] = 1;
                    new_leafs.push_back(v);
                }
            }
            cnt -= 1;
        }
        leafs = new_leafs;
    }
    cout << max(cnt, 0LL) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie();
    int t = 1; cin >> t;
	while(t--) solve();
    return 0;
}