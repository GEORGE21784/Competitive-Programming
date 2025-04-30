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
const int MAX = (int)2e5;
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

struct str {
    int l, r, c;
    bool operator < (const str& other) const {
        if(l != other.l) return l < other.l;
        return r < other.r;
    }
};

int dp[MAX];
void solve() {
    int n, w, h; cin >> n >> w >> h;
    vector<str> a(n);
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r, i};
    }
    sort(all(a));
    // cout << '\n';
    // for(auto&[l, r, c] : a) {
    //     cout << l << ' ' << r << ' ' << c << '\n';
    // }
    // return;
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        for(int j = i + 1; j < n; j++) {
            // hay una arista entre (i , j);
            str u = a[i];
            str v = a[j];
            if(u.l < v.l && u.r < v.r) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int idx = -1, mx = 0;
    for(int i = 0; i < n; i++) {
        str u = a[i];
        if(w < u.l && h < u.r && dp[i] > mx) {
            mx = dp[i];
            idx = i;
        }
    }
    if(idx == -1) {cout << "0\n"; return;}
    vector<int> path = {a[idx].c};
    int cnt = dp[idx];
    w = a[idx].l;
    h = a[idx].r;
    while(--cnt) {
        for(int i = idx + 1; i < n; i++) {
            if(dp[i] == dp[idx] - 1 && w < a[i].l && h < a[i].r) {
                path.push_back(a[i].c);
                idx = i;
                w = a[i].l;
                h = a[i].r;
                break;
            }
        }
    }
    cout << sz(path) << '\n';
    for(int x : path) cout << ++x << " ";
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