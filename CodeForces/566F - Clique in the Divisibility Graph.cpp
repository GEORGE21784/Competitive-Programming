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

const int inf = (int)2e18;
const int MAX = (int)1e6+5;
// const int mod = 998244353;
const int mod = (int)1e9+7;
const int LOG = 18;
const ld eps = (ld)10e-8;
int dp[MAX];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
        dp[x] = 1;
    }
    for(int i = n-1; i >= 0; i--) {
        int &x = a[i];
        for(int j = x*2; j < MAX; j+=x) {
            dp[x] = max(dp[x], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp+MAX-1) << '\n';
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