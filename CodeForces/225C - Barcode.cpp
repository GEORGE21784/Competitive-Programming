#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define ok(x) cout<<(x?"YES":"No solution")<<'\n'
#define ld long double

using namespace std;
typedef pair<int,int> ii;

const int inf = (int)1e9;
const int MAX = (int)2e3;
// const int MOD = 998244353;
const int MOD = (int)360;
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

int dp[MAX][2];
char g[MAX][MAX];
int ps[MAX];

/*
    (i, 0) -> la minima cantidad de cambios si 
              la i-th posicion termina en '#'
    (i, 1) -> ...
              ...                         '.' 
*/

void solve() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> g[i][j];
    }
    for(int j = 1; j <= m; j++) {
        ps[j] = ps[j - 1];
        for(int i = 1; i <= n; i++) {
            ps[j] += (g[i][j] == '#');
        }
    }
    for(int i = 1; i <= m; i++) {
        dp[i][0] = dp[i][1] = inf;
        for(int k = l; k <= r; k++) {
            if(i - k >= 0) {
                int ct = ps[i] - ps[i - k];
                int pt = k * n - ct;
                dp[i][0] = min(dp[i][0], dp[i - k][1] + pt);
                dp[i][1] = min(dp[i][1], dp[i - k][0] + ct);
            }
        }
    }
    cout << min(dp[m][0], dp[m][1]) << '\n';
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