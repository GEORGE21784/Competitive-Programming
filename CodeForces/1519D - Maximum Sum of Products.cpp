#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)5e3+7;
const int MOD = (int)1e9+7;
// const int MOD = (int)998244353;
int a[MAX];
int b[MAX];
int ps[MAX];
int dp[MAX][MAX];

int get(int l, int r) {
    if(l == r) 
        return a[l] * b[l];
    if(l + 1 == r) 
        return a[l] * b[r] + a[r] * b[l];
    int &ans = dp[l][r];
    if(ans) return ans;
    return ans = get(l + 1, r - 1) + a[l] * b[r] + a[r] * b[l];
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1; i <= n; i++) 
        cin >> b[i];
        
    for(int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i] * b[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) {
        int S = ps[i - 1] + ps[n] - ps[j];
        ans = max(ans, S + get(i, j));
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