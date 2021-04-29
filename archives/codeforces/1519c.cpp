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

#define mxn 200005
int n;
vi u, s;
map<int, vl> m;
map<int, vl> sum;
ll ans[mxn];

void debug() {

    for (auto p : sum) {
        cout << p.fi << ": ";
        for (ll x : p.se) {
            cout << x << " ";
        }
        cout << ln;
    }
}

void solve()
{
    u.clear(); s.clear();
    m.clear();
    sum.clear();
    memset(ans, 0, sizeof(ans));
    cin >> n;
    forn(i, n) {
        ll tmp;
        cin >> tmp;
        u.push_back(tmp);
    }
    forn(i, n) {
        ll tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    forn(i, n) {
        m[u[i]].push_back(s[i]);
    }
    for (auto p : m) {
        sort(p.se.rbegin(), p.se.rend());
        ll tmpsum = 0;
        for (ll x : p.se) {
            tmpsum += x;
            sum[p.fi].push_back(tmpsum);
        }
        for (int k = 1 ; k <= n && k <= sum[p.fi].size(); k++) {
            int idx = floor(sum[p.fi].size() / k) * k;
            ans[k] += sum[p.fi][idx - 1];
        }
    }
    // debug();

    for (int k = 1 ; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << ln;
}

int main()
{
    fast_cin();
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