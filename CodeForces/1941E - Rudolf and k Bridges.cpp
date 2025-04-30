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
const int MAX = (int)1e3;
// const int MOD = 998244353;
const int MOD = (int)1e8;
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

void solve() {
    int n, m, k, d; cin >> n >> m >> k >> d;
    ++d;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int &x = a[i][j];
            cin >> x;
            ++x;
        }
    }
    vector<int> b;
    for(int i = 1; i <= n; i++) {
        vector<int> &c = a[i];
        vector<int> dp(m+1, inf);
        dp[m] = c[m];
        multiset<int> st = {dp[m]};
        for(int j = m - 1; j > 0; j--) {
            dp[j] = c[j] + *(st.begin());
            st.insert(dp[j]);
            if(sz(st) > d) st.erase(st.find(dp[j + d]));
        }
        b.push_back(dp[1]);
    }
    int slide = 0;
    for(int i = 0; i < k; i++) slide += b[i];
    int ans = slide;
    for(int i = k; i < n; i++) {
        slide += b[i];
        slide -= b[i - k];
        ans = min(ans, slide);
    }
    cout << ans << '\n';
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