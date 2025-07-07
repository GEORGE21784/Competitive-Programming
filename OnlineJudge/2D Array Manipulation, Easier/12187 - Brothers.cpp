#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = (int)1e9;
const int MAX = (int)5e5 + 7;
int n, r, c, k;

void solve() {    
    vector<vi> g(r + 2, vi(c + 2, inf));
    for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) {
        cin >> g[i][j];
    }
    vector<vi> cur(r + 2, vi(c + 2, inf));
    while(k--) {
        for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) {
            bool damage = false;
            damage |= (g[i - 1][j]) == (g[i][j] - 1 + n) % n;
            damage |= (g[i + 1][j]) == (g[i][j] - 1 + n) % n;
            damage |= (g[i][j - 1]) == (g[i][j] - 1 + n) % n;
            damage |= (g[i][j + 1]) == (g[i][j] - 1 + n) % n;
            cur[i][j] = (g[i][j] - damage + n) % n;
        }
        g = cur;
    }
    for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) {
        cout << g[i][j] << " \n"[j == c];
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(cin >> n >> r >> c >> k) {
        if(n && r && c && k) solve();
    } 
    return 0;
}