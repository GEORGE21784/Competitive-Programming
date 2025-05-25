#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;
typedef pair<string, string> iss;

const int inf = (int)1e18;
const int MAX = (int)1e3 + 7;
int n;
int id[MAX], won[MAX];

void solve() {
    for(int i = 1; i <= n; i++) {
        cin >> id[i] >> won[i];
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int to = i + won[i];
        if(to >= 1 && to <= n) 
            ans[to] = id[i];
    }
    for(int i = 1; i <= n; i++) {
        if(!ans[i]) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(cin >> n) {
        if(n) solve();
    } 
    return 0;
}
