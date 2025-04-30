#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)1e6+7;
const int MOD = (int)1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ii> dp[MAX];

    auto add = [&](int k) -> void {
        int S = sz(dp[k]);
        if(S > 1) dp[k][S - 1].fi = (dp[k][S - 1].fi + dp[k][S - 2].fi) % MOD;
        return;
    };

    for(int i = 1; i <= n; i++) {
        int x = a[i];
        vector<int> div;
        for(int j = 1; j*j <= x; j++) {
            if(!(x % j)) {
                div.push_back(j);
                if(j*j != x) div.push_back(x/j);
            }
        }
        sort(div.begin(), div.end());
        for(int &d : div) {
            // ii add = {0, i};
            if(d == 1) {
                dp[d].push_back({1, i});
            } else {
                int S = sz(dp[d - 1]);
                if(S) {
                    if(dp[d - 1].back().se == i && S > 1) dp[d].push_back({dp[d - 1][S - 2].fi, i});
                    if(dp[d - 1].back().se != i) dp[d].push_back({dp[d - 1].back().fi, i});
                }
            }
            add(d);
        }
    }

    int ans = 0;
    for(int i = 1; i < MAX; i++) {
        if(sz(dp[i])) ans = (ans + dp[i].back().fi) % MOD;
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