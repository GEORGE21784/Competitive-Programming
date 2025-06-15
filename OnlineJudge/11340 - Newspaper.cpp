#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define fi first
#define se second
#define sz(x) (int)x.size()
#define ld long double

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 2e5+7;
const ll INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;
    
    vi val(300);
    while(n--) {
        char x; 
        int v;
        cin >> x >> v;
        val[x] = v;
    }

    cin >> n;
    cin.ignore();

    int ans = 0;
    while(n--) {
        string s;
        getline(cin, s);
        for(char c : s) ans += val[c];
    }
    
    cout << ans/100 << '.';
    if(ans % 100 < 10) {
        cout << 0;
    }
    cout << ans % 100 << "$\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
