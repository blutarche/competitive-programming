#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pl>> vvpl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;

ld eps = 1e-12;
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

#define mxn 200005
int n;
map<ld, vi> m;
bool used[mxn];
vector<pair<int, vi>> vv;
vector<pair<int, int>> ans_array;

int gcd(int a, int b) {
    if ( a < 0 ) a = -a;
    if ( b < 0 ) b = -b;
    while ( b != 0 ) {
        a %= b;
        if ( a == 0 ) return b;
        b %= a;
    }
    return a;
}

ld round_dec (ld x) {
    ld precision = pow(10, 9);
    return round(x * precision) / precision;
}

void solve()
{
    memset(used, 0, sizeof(used));
    vv.clear();
    cin >> n;
    forn (i, n) {
        ld a, b, c, d;
        cin >> a >> b >> c >> d;
        ld x = a / b;
        ld y = c / d;
        ld mx = round_dec((x + 1) / y);
        ld my = round_dec(x / (y + 1));
        m[mx].push_back(i + 1);
        m[my].push_back(i + 1);
    }
    for (auto map_val: m) {
        if (map_val.se.size() >= 2) {
            vv.push_back(mp(map_val.se.size(), map_val.se));
        }
    }
    sort(vv.begin(), vv.end());
    // for (auto pp: vv) {
    //     cout << pp.fi << " " << pp.se.size() << ln;
    // }

    for (auto map_val : vv) {
        // pair<pi, pi> p = map_val.fi;
        // pi x = p.fi;
        // pi y = p.se;
        // cout << x.fi << "/" << x.se << " , " << y.fi << "/" << y.se << " ==> ";'
        // ld x = map_val.fi;
        // if (__DEBUG__) cout << x << " : ";
        int a = -1, b = -1;
        for (int idx : map_val.se) {
            if (__DEBUG__) cout << idx << " ";
            if (used[idx]) continue;
            if (a != -1 && b != -1) {
                used[a] = true;
                used[b] = true;
                ans_array.push_back(mp(a, b));
                a = -1;
                b = -1;
            }
            if (a == -1) {
                a = idx;
            } else if (b == -1) {
                b = idx;
            }
        }
        if (a != -1 && b != -1) {
            used[a] = true;
            used[b] = true;
            ans_array.push_back(mp(a, b));
            a = -1;
            b = -1;
        }
        if (__DEBUG__) cout << ln;
    }
    cout << ans_array.size() << ln;
    for (auto p : ans_array) {
        cout << p.fi << " " << p.se << ln;
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