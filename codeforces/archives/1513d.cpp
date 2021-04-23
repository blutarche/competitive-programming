#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pll>> vvll;
typedef vector<pll> vll;
typedef vector<pii> vii;
ll MOD = 998244353;
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
#define se second #define el endl
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define MOD 1000000007

#define mxN 200005

vii v;
int a[mxN];
int n, p;
bool u[mxN];
bool ver[mxN];

void solve()
{
    // reset
    v.clear();
    memset(u, false, sizeof(u));
    memset(ver, false, sizeof(u));
    // input
    scanf("%d %d", &n, &p);
    forn(i, n)
    {
        scanf("%d", &a[i]);
        v.push_back(mp(a[i], i));
    }
    ll ans = 0;
    ll vcnt = 0;
    // sort
    sort(v.begin(), v.end());
    forn(k, n)
    {
        pii x = v[k];
        int y = x.first;
        u[x.second] = true;
        if (y > p)
        {
            continue;
        }
        // left
        for (int i = x.second - 1; i >= 0; i--)
        {
            if (a[i] % y != 0)
                break;
            if (ver[i])
                break;
            ver[i] = true;
            ans += y;
            vcnt++;
            if (u[i])
                break;
            u[i] = true;
        }
        // right
        for (int i = x.second + 1; i < n; i++)
        {
            if (a[i] % y != 0)
                break;
            if (ver[i - 1])
                break;
            ver[i - 1] = true;
            ans += y;
            vcnt++;
            if (u[i])
                break;
            u[i] = true;
        }
    }
    // cout << ans << " " << vcnt << el;
    ans += (n - 1 - vcnt) * p;
    cout << ans << el;
    // cout << "--" << el;
}

int main()
{
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