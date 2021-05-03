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

#define mxn 1e9
ll n;
map<ll,bool> m;

void solve()
{
    cin >> n;
    if (m[n]) cout << "YES" << ln;
    else cout << "NO" << ln;
}

void preprocess() {
    ll x = 2;
    ll j = 1;
    while (x<=mxn) {
        m[x] = true;
        x += (2*j + 1) * 2;
        j++;
    }
    x = 4;
    j = 1;
    while (x<=mxn) {
        m[x] = true;
        x += (2*j + 1) * 4;
        j++;
    }
    // cout << m.size() << ln;
    // for(auto x: m) {
    //     cout << x.fi << ln;
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