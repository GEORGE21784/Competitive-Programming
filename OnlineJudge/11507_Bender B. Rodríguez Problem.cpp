#include <bits/stdc++.h>

#define in long long
#define sz(x) (int)x.size()
#define LSOne(S) ((S) & (-S))
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;
typedef pair<string, string> iss;

const int inf = (int)1e18;
const int MAX = (int)2e4 + 7;
int n;

map<iss, string> mp;

void solve() {
    string cur = "+x";
    for(int i = 1; i < n; i++) {
        string s;
        cin >> s;
        if(s == "No") continue;
        if(cur == "-x") {
            cur = (s[0] == '+' ? '-' : '+');
            cur += s[1];
        } else if(cur == "+x") {
            cur = s;
        } else {
            if(s[1] != cur[1]) continue;
            assert(mp.count({cur, s}));
            cur = mp[{cur, s}];
        }
    }
    cout << cur << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // (cur, pos) = next
    mp[{"+y", "+y"}] = "-x";
    mp[{"-x", "+y"}] = "-y";
    mp[{"-y", "+y"}] = "+x";
    
    mp[{"-y", "-y"}] = "-x";
    mp[{"-x", "-y"}] = "+y";
    mp[{"+y", "-y"}] = "+x";
    
    mp[{"+z", "+z"}] = "-x";
    mp[{"-x", "+z"}] = "-z";
    mp[{"-z", "+z"}] = "+x";

    mp[{"-z", "-z"}] = "-x";
    mp[{"-x", "-z"}] = "+z";
    mp[{"+z", "-z"}] = "+x";
    
    int t = 1; //cin >> t;
    while(cin >> n) {
        if(n) solve();
    } 
    return 0;
}