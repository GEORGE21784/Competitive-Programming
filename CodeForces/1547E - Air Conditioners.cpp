#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e15;
const int MAX = (int)5e2+7;
const int MOD = (int)1e9+7;
// const int MOD = (int)998244353;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(k);
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }
    vector<int> a(n + 1, inf);
    for(int i = 0; i < k; i++) {
        int t; cin >> t;
        a[ b[i] ] = t;
    }

    vector<int> dp1(n + 2, inf);
    for(int i = 1; i <= n; i++) {
        dp1[i] = min(dp1[i - 1] + 1, a[i]);
    }
    
    vector<int> dp2(n + 2, inf);
    for(int i = n; i > 0; i--) {
        dp2[i] = min(dp2[i + 1] + 1, a[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << min(dp1[i], dp2[i]) << " \n"[i == n];
    }
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