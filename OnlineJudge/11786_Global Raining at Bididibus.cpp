#include <bits/stdc++.h>

#define in long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)2e4 + 7;

// mp[i] = first occurrence of a "\" at the i-th position from the left

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;
    map<int, int> mp;
    int ans = 0, p = 1;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '\\') {
            if(s[i - 1] != '/') p -= 1;
            mp[p] = i;
        } 
        if(s[i] == '/') {
            if(s[i - 1] == '/') p += 1;
            if(mp.count(p)) ans += (i - mp[p]);
        }
        if(s[i] == '_') p += (s[i - 1] == '/');
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
