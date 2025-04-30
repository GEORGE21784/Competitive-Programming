#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

void solve() {
	int n; cin >> n;
	set<int> st;
	map<int, vector<int>> mp;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		mp[x].push_back(i);
		st.insert(x);
	}
	vector<int> a(all(st));
	n = sz(a);
	vector<int> ans;
	int l = 0, r = n+1;
	while(r - l > 1) {
		int m = l + (r - l) / 2;
		bool ok = false;
		for(int i = 0; i <= n-m; i++) {
			if( a[i+m-1] == a[i]+m-1 ) {
				bool can = true;
				vector<int> path;
				for(int x = a[i]; x <= a[i]+m-1; x++) {
					auto it = lower_bound(all(mp[x]), sz(path) ? path.back() : -1);
					if( it == mp[x].end() ) {
						can = false;
						break;
					} else {
						path.push_back(*it);
					}
				}
				if( can ) {
					ok = true;
					ans = path;
					break;
				}
			}
		}
		if( ok ) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << '\n';
	for(int x : ans) cout << x << ' ';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}