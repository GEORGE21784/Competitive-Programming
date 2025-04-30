#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)2e5+7;
const int MOD = (int)1e9+7;
int n, m;
vector<int> g[MAX];
int color[MAX];
int dis[MAX];

ii bfs(int u) {
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(!dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    dis[u] = 0;
    // (u, dis)
    ii ans = {0, 0};
    for(int i = 1; i <= m; i++) {
        if(dis[color[i]] > ans.se) {
            ans = {color[i], dis[color[i]]};
        }
    }
    for(int i = 1; i <= n; i++) dis[i] = 0;
    return ans;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) g[i].clear(), color[i] = 0;
    for(int i = 1; i <= m; i++) {
        cin >> color[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(m == 1) {
        cout << "0\n";
        return;
    }
    int A = color[1];
    int B = bfs(A).fi;
    int C = (bfs(B).se + 1) / 2;
    cout << C << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}