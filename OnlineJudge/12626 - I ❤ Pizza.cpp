#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define sz(x) (int)x.size()

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 2e5+7;
const int INF = 1e18;
const int MOD = 1e9+7;

//MARGARITA

int f(char x, string s) {
    return count(s.begin(), s.end(), x);
}

void solve() {    
    string s;
    cin >> s;
    int ans = min({
        f('A', s) / 3,
        f('R', s) / 2,
        f('M', s),
        f('G', s),
        f('I', s),
        f('T', s),
    });
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
