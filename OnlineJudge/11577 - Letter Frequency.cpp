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

void solve() {    
    string s;
    getline(cin, s);
    
    vi f(300);
    for(char c : s) if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) f[c] += 1;
    for(int i = 'A'; i <= 'Z'; i++) f[i + 32] += f[i], f[i] = 0;
    int mx_f = *max_element(f.begin(), f.end());
    for(int i = 'a'; i <= 'z'; i++) if(f[i] == mx_f) {
        cout << (char)i;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; cin >> t;
    cin.ignore();
    while(t--) solve();
    return 0;
}
