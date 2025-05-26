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
    vector<string> a(5, "00000"), b;
    for(int i = 1; i <= 3; i++) {
        cin >> a[i];
        a[i] = "0" + a[i] + "0";
    }
    vector< vector<string> > S = {a};
    for(int k = 1; k < MAX; k++) {
        b.assign(5, "00000");
        for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) {
            int sm = 0;
            sm += a[i - 1][j] - '0';
            sm += a[i + 1][j] - '0';
            sm += a[i][j - 1] - '0';
            sm += a[i][j + 1] - '0';
            b[i][j] = '0' + (sm % 2);
        }
        if(find(S.begin(), S.end(), b) != S.end()) {
            cout << k-2 << '\n';
            return;
        }
        S.push_back(b);
        a = b;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    } 
    return 0;
}