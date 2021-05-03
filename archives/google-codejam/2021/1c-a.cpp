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
bool __DEBUG__ = false;

#define mxn 100
int n, k;
vi v;
vi u;
map<int, bool> m;
double max1, max2, maxtri;

void debug() {
    if (!__DEBUG__) return;
    cout << "v: ";
    forn(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << ln;
}

void solve()
{
    v.clear(); m.clear();
    max1 = 0; max2 = 0; maxtri = 0;
    cin >> n >> k;
    forn (i, n) {
        int tmp;
        cin >> tmp;
        if (!m[tmp]) {
            v.push_back(tmp);
        }
        m[tmp] = true;
    }
    sort(v.begin(), v.end());
    //head
    max1 = v[0] - 1;
    debug();
    if (__DEBUG__) {
        cout << "max: " << max1 << " " << max2 << " " << maxtri << ln;
    }
    // between
    for (int i = 1; i < v.size(); i++) {
        int diff = v[i] - v[i - 1] - 1;
        int x = ceil(1.0 * diff / 2.0);
        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }
        if (diff > maxtri) {
            maxtri = diff;
        }
        debug();
        if (__DEBUG__) {
            cout << "max: " << max1 << " " << max2 << " " << maxtri << ln;
        }
    }
    // tail
    int x = k - v[v.size() - 1];
    if (x > max1) {
        max2 = max1;
        max1 = x;
    } else if (x > max2) {
        max2 = x;
    }
    if (__DEBUG__) {
        cout << "max: " << max1 << " " << max2 << " " << maxtri << ln;
    }
    if (max1 + max2 > maxtri) {
        cout << (max1 + max2) / k << ln;
    } else {
        cout << maxtri / k << ln;
    }
}

int main()
{
    fast_cin();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    // solve();

    return 0;
}