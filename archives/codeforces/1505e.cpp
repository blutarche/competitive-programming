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
#define se second
#define el endl
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 100
char g[mxN][mxN];
int r, c;
int ans = 0;

void eat(int y, int x)
{
    if (y < 0 || y > r || x < 0 || x > c)
        return;
    if (g[y][x] == '*')
        ans++;
}

void solve()
{
    memset(g, 0, sizeof(g));
    ans = 0;

    cin >> r >> c;
    forn(i, r)
    {
        string s;
        cin >> s;
        forn(j, s.length())
        {
            g[i + 1][j + 1] = s[j];
        }
    }
    int y = 1, x = 1;
    eat(y, x);
    while (y != r || x != c)
    {
        if (g[y][x + 1] == '*' && x < c)
        {
            x++;
        }
        else if (g[y + 1][x] == '*' && y < r)
        {
            y++;
        }
        else if (x < c)
        {
            x++;
        }
        else
        {
            y++;
        }
        // cout << y << " " << x << el;
        eat(y, x);
        if (y == r && x == c)
        {
            break;
        }
    }
    cout << ans << el;
}

int main()
{
    // int T;
    // cin >> T;
    // forn(i, T)
    // {
    //     cout << "Case #" << i + 1 << ": ";
    //     solve();
    // }
    solve();

    return 0;
}