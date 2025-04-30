#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> ii;

#define sz(x) (int)x.size()
#define ff first
#define ss second
#define ld long double
const int inf = (int)2e10;
const int MAXN = (int)2e5;
const int MAX = (int)1e5;
const ld esp = (ld)10e-8;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    vector<int> ps(n+1);
    for(int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + (s[i] == 'b');
    }
    auto f = [&](int x) -> bool {
        for(int r = x; r <= n; r++) {
            int A = x - (ps[r] - ps[r-x]);
            if(ps[r] - ps[r-x] <= k || A <= k) {
                return true;
            }
        }
        return false;
    };
    int l = 0, r = n+1, mid;
    while(r - l > 1) {
        mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
} 

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);            
    int t = 1;
    // cin >> t;
    for(int _  = 0; _  < t; _++) {
        solve();
    }
    return 0;
}