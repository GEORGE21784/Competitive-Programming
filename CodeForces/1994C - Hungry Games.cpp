#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> ii;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ff first
#define ss second

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ps(n+1);
	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i-1] + a[i];
	}
	vector<int> dp(n+5);
	for(int i = n; i >= 1; i--) {
		int l = i, r = n+1;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if( ps[mid] - ps[i-1] <= x ) l = mid;
			else r = mid;
		}
		dp[i] = l - i + 1 + dp[r+1];
		if( l == i && a[i] > x ) 
			dp[i] = dp[r];
	}
	cout << accumulate(all(dp), 0LL) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int _ = 0; _ < t; _++) {
		solve();
	}
	return 0;
}