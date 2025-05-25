#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

const int inf = (int)1e18;
const int MAX = (int)1e5 + 7;
int n, m;
int l[MAX], r[MAX];

void f(int x) {
    if(x < 1 || x > n) cout << "*";
    else cout << x;
}

void solve() {
    for(int i = 1; i <= n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    while(m--) {
        int i, j;
        cin >> i >> j;
        f(l[i]); cout << ' '; f(r[j]);
        cout << '\n';

        r[ l[i] ] = r[j];
        l[ r[j] ] = l[i];
    }
    cout << "-\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(cin >> n >> m) {
        if(n + m > 0) solve();
    } 
    return 0;
}