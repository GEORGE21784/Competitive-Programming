#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e15;
const int MAX = (int)5e5 + 7;

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    s = '-' + s;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '-') {
            if(((i + 1 <= n && s[i + 1] != 'B' && s[i + 1] != 'S') || (i + 1 > n) )
                && ((i + 2 <= n && s[i + 2] != 'B') || (i + 2 > n))
                && ((i - 1 > 0 && s[i - 1] != 'S') || (i - 1 < 1)) ) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    } 
    return 0;
}