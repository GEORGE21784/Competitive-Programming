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

set<string> st;

bool f(char x) {
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

void solve() {
    string s;
    while(cin >> s) {
        int n = sz(s);
        for(int i = 0; i < n; i++) {
            if(f(s[i])) {
                int j = i;
                while(j < n && f(s[j]) == f(s[i])) {
                    if(s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;
                    j += 1;
                }
                st.insert(s.substr(i, j - i));
                i = j;
            }
        }
    }
    for(auto S : st) cout << S << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
