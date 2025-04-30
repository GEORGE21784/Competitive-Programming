#include <bits/stdc++.h>

// #define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)3e5+7;
const int MOD = (int)1e9+7;
// const int MOD = (int)998244353;
int n, m;
string s;
vector<int> g[MAX];
bool vis[MAX];
int C[MAX];
int dp[MAX][26];

bool dfs(int u) {
    if(C[u] != -1) return C[u];
    if(vis[u]) return C[u] = true;
    vis[u] = 1;
    for(int v : g[u]) if(dfs(v)) return C[u] = true;
    return C[u] = false;
}

int get(int u, char c) {
    int &ans = dp[u][c - 'a'];
    if(ans != -1) 
        return ans;
    dp[u][c - 'a'] = (s[u] == c);
    for(int v : g[u]) dp[u][c - 'a'] = max(dp[u][c - 'a'], get(v, c) + (s[u] == c));
    return ans;
}

void solve() {
    cin >> n >> m >> s;
    s = ' ' + s;
    memset(C, -1, sizeof(C));
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    bool cycle = false;
    for(int i = 1; i <= n; i++) if(!vis[i]) cycle |= dfs(i);
    if(cycle) {cout << "-1\n"; return;}
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 1; i <= n; i++) for(char c = 'a'; c <= 'z'; c++) {
        ans = max(ans, get(i, c));
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}