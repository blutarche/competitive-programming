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

#define mxn 5001
int n;
vl a, b;
ll dp[mxn][mxn];
ll dp_sum[mxn];

void solve()
{
    cin >> n;
    forn (i, n) {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    forn (i, n) {
        ll tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    memset(dp, 0, sizeof(dp));
    ll tmpsum = 0;
    forn(i, n) {
        dp[i][i] = a[i] * b[i];
        tmpsum += a[i] * b[i];
        dp_sum[i] = tmpsum;
    }
    forn (i, n - 1) {
        // odd
        for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
            dp[l][r] = dp[l + 1][r - 1] + (a[r] * b[l]) + (a[l] * b[r]);
        }
        // even
        dp[i][i + 1] = a[i + 1] * b[i] + a[i] * b[i + 1];
        for (int l = i - 1, r = i + 2; l >= 0 && r < n; l--, r++) {
            dp[l][r] = dp[l + 1][r - 1] + (a[r] * b[l]) + (a[l] * b[r]);
        }
    }
    ll max = -1;
    forn (i, n) {
        for (int j = i; j < n; j++) {
            ll before = 0, after = 0, swap;
            if (i > 0) {
                before = dp_sum[i - 1];
            }
            if (j < n) {
                after = dp_sum[n - 1] - dp_sum[j];
            }
            swap = dp[i][j];
            ll tmpsum = before + after + swap;
            if (tmpsum > max) {
                max = tmpsum;
            }
            // cout << before << ":" << swap << ":" << after << "\t" << " ";
        }
        // cout << ln;
    }
    cout << max << ln;
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