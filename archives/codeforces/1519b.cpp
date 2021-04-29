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

#define INF 2e18
ll MOD = 998244353;

#define mxn 102
#define mxk 10002
int n, m, k;
bool g[mxn][mxn][mxk];

void solve()
{
    cin >> n >> m >> k;
    if (g[n][m][k]) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

void preprocess() {
    memset(g, false, sizeof(g));
    g[1][1][0] = true;
    for (int i = 1; i < mxn; i++) {
        for (int j = 1; j < mxn; j++) {
            int r_cost = i;
            int d_cost = j;
            for (int k = 0; k < mxk; k++) {
                if (k + d_cost < mxk) {
                    g[i][j][k + d_cost] = g[i - 1][j][k];
                }
                if (k + r_cost < mxk) {
                    g[i][j][k + r_cost] = g[i][j - 1][k];
                }
            }
        }
    }
    // for (int i = 0; i < mxn; i++) {
    //     for (int j = 0; j < mxn; j++) {
    //         for (int k = 0; k < mxk; k++) {
    //             cout << g[i][j][k] << ":";
    //         }
    //         cout << " ";
    //     }
    //     cout << ln;
    // }
}

int main()
{
    fast_cin();
    preprocess();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
    }
    // solve();

    return 0;
}