#include <bits/stdc++.h>

// #define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define ok(x) cout<<(x?"YES":"NO")<<'\n'
#define ld long double

using namespace std;
typedef pair<int,int> ii;

const int inf = (int)1e9;
const int MAX = (int)2e5;
// const int MOD = 998244353;
const int MOD = (int)1e9+7;
const int LOG = 18;
const ld EPS = (ld)1e-8;
const ld PI = 3.141592653589793;

int binpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1LL) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b = (b >> 1LL);
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if((n+m-1) % 2) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> mn(n+1, vector<int>(m+1, inf)), mx(n+1, vector<int>(m+1, -inf));
    mn[1][1] = mx[1][1] = a[1][1];
    for(int i = 2; i <= n; i++) {
        mx[i][1] = mn[i][1] = mx[i - 1][1] + a[i][1];
    }
    for(int i = 2; i <= m; i++) {
        mx[1][i] = mn[1][i] = mx[1][i - 1] + a[1][i];
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + a[i][j];
            mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + a[i][j];
        }
    }
    cout << (0 >= mn[n][m] && 0 <= mx[n][m] ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}