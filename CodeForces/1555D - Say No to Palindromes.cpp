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
// const int MOD = (int)998244353;

void solve() {
    int n, m; string s;
    cin >> n >> m >> s;
    s = ' ' + s;
    string S = "abc";
    vector<vector<int>> a;
    do {
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i++) b[i] = b[i - 1] + (s[i] != S[(i - 1) % 3]);
        a.push_back(b);
    } while(next_permutation(S.begin(), S.end()));
    for(; m; m--) {
        int l, r; cin >> l >> r;
        int ans = inf;
        for(auto& nx : a) ans = min(ans, nx[r] - nx[l - 1]);
        cout << ans << '\n';
    }
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