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
const int MAX = (int)3e5;
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
/*
* calcular el numero de carreteras malas en el arbol
si lo indexo en el nodo 1.
* calcular el numero de carreteras buenas de nodo 1 a u
*/ 

vector<int> g[MAX];
// direccion
set<int> st[MAX];
int good[MAX];
int d[MAX];
int dfs(int u, int p) {
    int cnt = 0;
    for(int v : g[u]) {
        if(v != p) {
            cnt += (!st[u].count(v)) + dfs(v, u); 
        }
    }
    return cnt;
}

void dfs2(int u, int p, int cnt) {
    good[u] = cnt;
    d[u] = d[p] + 1;
    for(int v : g[u]) {
        if(v != p) {
            dfs2(v, u, cnt + (st[u].count(v)));

        }
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        st[u].insert(v);
    }
    int cnt = dfs(1, 0);
    dfs2(1, 0, 0);
    vector<int> ans;
    int mn = inf;
    for(int i = 1; i <= n; i++) {
        --d[i];
        int inv = cnt - (d[i] - good[i]) + good[i];
        if(inv < mn) {
            ans = {i};
            mn = inv;
            continue;
        }
        if(inv == mn)
            ans.push_back(i);
    }
    cout << mn << '\n';
    for(int x : ans) cout << x << ' ';
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