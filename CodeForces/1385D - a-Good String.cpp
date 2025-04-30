#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> ii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define db long double
const int MAX = 300;
const int inf = 1E18;
const db EPS = 1E-9;
const int lg = 17;
int n, mn;
string s;

vector<vector<int>> ps;

void f(int l, int r, char c, int x){
	if( l == r ){
		mn = min(mn, x + (s[l] != c) );
		return;
	}
	int i = (int) c - 'a';
	int m = (l + r) >> 1, seg = (r-l+1) >> 1;
	int cl = ps[i][m] - ps[i][l-1];
	int cr = ps[i][r] - ps[i][m];
	f(m+1, r, c+1, x + seg - cl);
	f(l, m, c+1, x + seg - cr);
}

void solve(){
	cin >> n >> s;
	ps.assign(130, vector<int>(n+1));
	s = '$' + s;
	for(int i = 'a'; i <= 'z'; i++){
		for(int j = 1; j <= n; j++){
			int ii = i-((int)'a');
			ps[ii][j] = ps[ii][j-1] + ((int)s[j] == i);
		}
	}
	mn = inf;
	f(1, n, 'a', 0);
	cout << mn << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while( t-- ){
		solve();
	}
	return 0;
}