#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> ii;

#define sz(x) (int)x.size()
#define ff first
#define ss second
#define ld long double
const int inf = (int)2e10;
const int MAXN = (int)3e5;
const ld esp = (ld)10e-8;
int value[MAXN];
vector<vector<int>> adj;
int m;
bool dfs(int u, int acc) {
    if(sz(adj[u]) == 0) {
        return value[u] >= acc;
    }
    if(acc > inf) {
        return false;
    }
    for(int v : adj[u]) {
        if(!dfs(v, (u == 1 ? m - value[1] : acc + max(0LL, acc - value[u])))) {
            return false;
        }   
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    adj.assign(n + 1, vector<int>());

    for(int i = 2; i <= n; i++) {
        int u; 
        cin >> u;
        adj[u].push_back(i);
    }

    int l = value[1], r = inf;
    while(l+1 < r) {
        m = l + (r - l) / 2;
        if(dfs(1, 0)) l = m;
        else r = m;
    }

    cout << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int _  = 0; _  < t; _++) {
        solve();
    }
    return 0;
}