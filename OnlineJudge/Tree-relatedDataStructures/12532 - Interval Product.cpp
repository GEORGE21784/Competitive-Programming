/* author: gerogeVT
*/
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define fi first
#define se second
#define LSOne(S) ((S) & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 2e5+7;
const int INF = 1e9;
const int MOD = 1e9+7;

/*
    this is a problem about range querys in wich
    i used Fenwick Tree as data structure for range sums,
    one BIT for zeros and another for negatives.
*/

class BIT {
    private:
        vi ft;
    public:
        void build(const vi &f) {
            int m = sz(f);
            ft.assign(m + 1, 0);
            for(int i = 1; i <= m; i++) {
                ft[i] += f[i];
                if(i + LSOne(i) <= m) {
                    ft[i + LSOne(i)] += ft[i];
                }
            }
        }
        
        BIT(const vi &f) {build(f);}

        void update(int i, int x) {
            for(; i < sz(ft); i+=LSOne(i)) {
                ft[i] += x;
            }
        }

        int RQ(int i) {
            int S = 0;
            for(; i; i-=LSOne(i)) {
                S += ft[i];
            }
            return S;
        }

        int RQ(int i, int j) {
            return RQ(j) - RQ(i - 1);
        }
};

int n, m;

void solve() {
    vi a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi zero(n + 1), neg(n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] < 0) neg[i] = 1;
        if(a[i] == 0) zero[i] = 1;
    }

    BIT ftNeg(neg), ftZero(zero);

    while(m--) {
        char o;
        int l, r;
        cin >> o >> l >> r;
        if(o == 'C') {
            if(a[l] == 0) ftZero.update(l, -1);
            if(a[l] < 0) ftNeg.update(l, -1);
            if(r == 0) ftZero.update(l, 1);
            if(r < 0) ftNeg.update(l, 1);
            a[l] = r;
        } else {
            if(ftZero.RQ(l, r)) {
                cout << "0";
            } else {
                cout << (ftNeg.RQ(l, r) % 2 ? '-' : '+');
            }
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while(cin >> n >> m) {
        solve();
    } 
    return 0;
}
