#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pl>> vvpl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;

double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define el endl
#define se second
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define INF 1e9
ll MOD = 998244353;

#define mxn 505
#define mxm 505
#define mxk 22

int n, m, k;
int u[mxn][mxm], l[mxn][mxm], r[mxn][mxm], d[mxn][mxm];
int dp[mxk][mxn][mxm];

void solve()
{
    memset(u, 0, sizeof(u));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    cin >> n >> m >> k;
    forn (i, n) {
        forn (j, m - 1) {
            int tmp;
            cin >> tmp;
            l[i][j + 1] = tmp;
            r[i][j] = tmp;
        }
    }
    forn (i, n - 1) {
        forn (j, m) {
            int tmp;
            cin >> tmp;
            u[i + 1][j] = tmp;
            d[i][j] = tmp;
        }
    }
    if (k % 2 == 1) {
        forn(i, n) {
            forn(j, m) {
                cout << -1 << " ";
            }
            cout << ln;
        }
        return;
    }
    memset(dp, 0, sizeof(dp));
    forn (kk, k/2) {
        forn(i, n) {
            forn(j, m) {
                dp[kk + 1][i][j] = 1e9;
                if (i > 0) {
                    dp[kk + 1][i][j] = min(dp[kk + 1][i][j], dp[kk][i - 1][j] + 2*d[i - 1][j]);
                }
                if (i < n - 1) {
                    dp[kk + 1][i][j] = min(dp[kk + 1][i][j], dp[kk][i + 1][j] + 2*u[i + 1][j]);
                }
                if (j > 0) {
                    dp[kk + 1][i][j] = min(dp[kk + 1][i][j], dp[kk][i][j - 1] + 2*r[i][j - 1]);
                }
                if (j < m - 1) {
                    dp[kk + 1][i][j] = min(dp[kk + 1][i][j], dp[kk][i][j + 1] + 2*l[i][j + 1]);
                }
            }
        }
        // forn(i, n) {
        //     forn(j, m) {
        //         cout << dp[kk+1][i][j] << " ";
        //     }
        //     cout << ln;
        // }
        // cout << "---" << ln;
    }
    forn(i, n) {
        forn(j, m) {
            cout << dp[k/2][i][j] << " ";
        }
        cout << ln;
    }
}

int main()
{
    fast_cin();
    // int T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    //     // cout << "Case #" << i + 1 << ": ";
    //     solve();
    // }
    solve();

    return 0;
}