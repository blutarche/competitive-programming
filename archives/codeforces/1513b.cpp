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
int n, k;
int a[mxN];

int b0[32];
int b1[32];
map<int, int> m;

void solve()
{
    memset(a, 0, sizeof(a));
    memset(b0, 0, sizeof(b0));
    memset(b1, 0, sizeof(b1));
    m.clear();
    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int aa = a[0];
    forn(i, n)
    {
        aa = aa & a[i];
    }
    ll sum = 1;
    sum *= m[aa];
    sum %= MOD;
    m[aa]--;
    sum *= m[aa];
    sum %= MOD;
    m[aa]--;
    forn(i, n - 2)
    {
        sum *= (n - 2 - i);
        sum %= MOD;
    }
    cout << sum << el;

    // cout << "----" << el;
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