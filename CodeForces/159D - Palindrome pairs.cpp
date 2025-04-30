#include<bits/stdc++.h>
using namespace std;

#define int long long 
typedef pair<int,int> ii;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ff first
#define ss second
const int inf = 1e18;
const int MAX = 3e3;
int n;
string s;
//    tam - pos
int dp[MAX][MAX];
void solve(){
	cin >> s;
	n = sz(s);
	s = '$' + s;
	
	for(int i = 1; i <= n; i++){
		dp[1][i] = 1;
		if( i+1 <= n && s[i] == s[i+1]){
			dp[2][i] = 1;
		}
	}
	
	for(int k = 3; k <= n; k++){
		for(int i = 1; i <= n-k+1; i++){
			if( s[i] == s[i+k-1] && dp[k-2][i+1] ){
				dp[k][i] = 1;
			}
		}
	}
	
	vector<int> ps(n+1);
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			cnt += dp[j][i];
		}
		ps[i] = ps[i-1] + cnt;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= n; k++){
			if( dp[k][i] ){
				ans += ps[n] - ps[i+k-1];
			}
		}
	}

	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	// cin >> tt;
	while( tt-- ){
		solve();
	}
	return 0;
}