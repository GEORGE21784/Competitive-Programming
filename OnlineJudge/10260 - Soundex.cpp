#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;
typedef vector<char> vc;

const int inf = (int)1e18+7;
const int MAX = (int)6e6+7;
const int mod = (int)1e9+7;

vector<vc> let = {
    {'B', 'F', 'P', 'V'},
    {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'},
    {'D', 'T'},
    {'L'},
    {'M', 'N'},
    {'R'}
};

int get(char c) {
    for(int i = 0; i < sz(let); i++) {
        auto it = find(let[i].begin(), let[i].end(), c);
        if(it != let[i].end()) {
            return i+1;
        }
    }
    return -1;
}

void solve() {
    string s;
    while(cin >> s) {
        int n = sz(s);
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && get(s[i]) == get(s[j])) {
                j += 1;
            }
            int ans = get(s[i]);
            if(ans != -1) {
                cout << ans;
            }
            i = j - 1;
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}