// gerogeVT
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5+7;
int n;
vector<int> t[MAX];
int c[MAX], sz_sub[MAX];
int parent[MAX];
int c_sub[MAX]; // respect to root
ii range[MAX];
vector<int> tour, b;

void dfs(int u, int p = 0) {
    parent[u] = p;
    range[u].fi = sz(tour);
    tour.push_back(c[u]);
    sz_sub[u] = 1;
    c_sub[u] = (c[u] == c[1]);
    for(int v : t[u]) if(v != p) {
        dfs(v, u);
        sz_sub[u] += sz_sub[v];
        c_sub[u] += c_sub[v];
    }
    range[u].se = sz(tour) - 1;
}

bool is_valid(int u) {
    if(u != 1 && c_sub[1] - c_sub[u] != sz_sub[1] - sz_sub[u]) {
        return false;
    }
    for(int v : t[u]) if(v != parent[u]) {
        int L = range[v].fi;
        int l = L, r = range[v].se + 1;
        while(r - l > 1) {
            int md = (l + r) / 2;
            if(b[md] - b[L] == md - L) {
                l = md;
            } else {
                r = md;
            }
        } 
        if(l != range[v].se) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    dfs(1);

    b = vector<int>(n, 1);
    for(int i = 1; i < n; i++) if(tour[i] == tour[i - 1]) b[i] = b[i - 1] + 1;

    for(int i = 1; i <= n; i++) {
        if(is_valid(i)) {
            cout << "YES\n" << i << '\n';
            return;
        }
    }

    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}