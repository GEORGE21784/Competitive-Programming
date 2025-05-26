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

void f(string s, int x) {
    while(x--) cout << s << ' ';
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x;
        cin >> x;
        x--;
        if(s[x] != "?") {
            cout << s[x] << '\n';
        } else {
            int l = x, r = x;
            while(l >= 0 && s[l] == "?") l -= 1;
            while(r < n && s[r] == "?") r += 1;
            if(l < 0) l = -inf;
            if(r >= n) r = inf;
            if(x - l == r - x) {
                cout << "middle of " << s[l] << " and " << s[r] << '\n';  
            } else if(x - l < r - x){
                f("right of", x - l);
                cout << s[l] << '\n';
            } else {
                f("left of", r - x);
                cout << s[r] << '\n';
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    } 
    return 0;
}