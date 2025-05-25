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
string s;
int l[MAX], r[MAX];

void solve() {
    int n = sz(s);
    s = ' ' + s;   
    l[0] = r[n + 1] = n+5;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'X') l[i] = -1;
        else l[i] = l[i - 1] + 1;
    }
    for(int i = n; i > 0; i--) {
        if(s[i] == 'X') r[i] = -1;
        else r[i] = r[i + 1] + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, min(l[i], r[i]));
    }
    cout << max(ans, 0LL) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(cin >> s) {
        solve();
    } 
    return 0;
}