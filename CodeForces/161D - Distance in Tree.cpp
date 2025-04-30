#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ok(x) cout<<(x?"YES":"NO")<<'\n'
#define ld long double

using namespace std;
typedef pair<int,int> ii;

const int inf = (int)2e9;
const int MAX = (int)1e5;
// const int MOD = 998244353;
const int MOD = (int)1e9+7;
const int LOG = 18;
const ld EPS = (ld)1e-8;
const ld PI = 3.141592653589793;
int gauss(int n) {return n * (n + 1) / 2;}
int binpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1LL) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b = (b >> 1LL);
    }
    return ans;
}
int n, k; 

vector<int> graph[MAX];
int dp[MAX][501];
int lev[MAX];
int par[MAX];
/*
    (u, k) # de nodos distancia k en el subarbol de u
*/
void dfs(int u, int p) {
    par[u] = p;
    dp[u][0] = 1;
    lev[u] = lev[p] + 1;
    for(int v : graph[u]) {
        if(v != p) {
            dfs(v, u);
            for(int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
    }
}

int dfs2(int u, int p, int acc) {
    if(u == 0)
        return 0;
    if(acc == k)
        return 1;
    int ans = dp[u][k - acc] - (p != -1 ? dp[p][k - acc - 1] : 0);
    ans += dfs2(par[u], u, acc + 1);
    return ans;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += dfs2(i, -1, 0);
    cout << (ans >> 1LL) << '\n';
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