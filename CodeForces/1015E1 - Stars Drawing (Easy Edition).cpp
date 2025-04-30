#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ld long double

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e9;
const int MAX = (int)2e6;
const int MOD = (int)1e9+7;

struct str {
    int a, b, c;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++) {
        string& s = a[i];
        cin >> s;
        s = ' ' + s;
    }
    vector<vector<int>> F(n + 1, vector<int>(m + 1)), C(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        F[i][j] = F[i][j - 1] + (a[i][j] == '*');
    }
    for(int j = 1; j <= m; j++) for(int i = 1; i <= n; i++){
        C[i][j] = C[i - 1][j] + (a[i][j] == '*');
    }
    auto f = [&](int x, int i, int j) -> bool {
        return (F[i][j + x] - F[i][j - x - 1]) == (x * 2 + 1) && 
        (C[i + x][j] - C[i - x - 1][j]) == (x * 2 + 1);
    };
    vector<ii> fil[n + 1], col[m + 1];
    vector<str> ans;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if((a[i][j] == '*')) {
            int l = 0, r = min({i - 1, j - 1, n - i, m - j}) + 1;
            while(r - l > 1) {
                int md = l + (r - l) / 2;
                if(f(md, i, j)) l = md; else r = md;
            }
            if(l) {
                ans.push_back({i, j, l});
                fil[i].push_back({j - l, j + l});
                col[j].push_back({i - l, i + l});
            } 
        }
    }
    for(int i = 1; i <= max(n, m); i++) {
        if(i <= n) sort(fil[i].begin(), fil[i].end());
        if(i <= m) sort(col[i].begin(), col[i].end());
    }
    vector<vector<int>> mark(n + 1, vector<int>(m + 1));
    for(int k = 1; k <= n; k++) {
        vector<ii>& b = fil[k];
        int N = sz(b);
        for(int i = 0; i < N; i++) {
            int j = i, mx = b[i].se;
            while((j < N) && !(b[j].fi > mx)) {
                mx = max(mx, b[j].se);
                j += 1;
            }
            for(int K = b[i].fi; K <= mx; K++) if(a[k][K] == '*') mark[k][K] = 1;
            i = j - 1;
        }
    }
    for(int k = 1; k <= m; k++) {
        vector<ii>& b = col[k];
        int N = sz(b);
        for(int i = 0; i < N; i++) {
            int j = i, mx = b[i].se;
            while((j < N) && !(b[j].fi > mx)) {
                mx = max(mx, b[j].se);
                j += 1;
            }
            for(int K = b[i].fi; K <= mx; K++) if(a[K][k] == '*') mark[K][k] = 1;
            i = j - 1;
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if((a[i][j] == '*') && (!mark[i][j])) {
        cout << "-1\n"; return;
    }
    cout << sz(ans) << '\n';
    for(auto[a, b, c] : ans) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
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