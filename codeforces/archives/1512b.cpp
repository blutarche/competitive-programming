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
#define se second
#define el endl
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 402
char g[mxN][mxN];
pii a, b;
int n;

void print()
{
    forn(i, n)
    {
        forn(j, n)
        {
            cout << g[i][j];
        }
        cout << el;
    }
}

void solve()
{
    cin >> n;
    forn(i, n)
    {
        scanf("%s", g[i]);
    }
    int c = 0;
    forn(i, n)
    {
        forn(j, n)
        {
            if (g[i][j] == '*')
            {
                if (c == 0)
                    a = mp(i, j);
                else
                    b = mp(i, j);
                c++;
            }
        }
    }
    // cout << a.fi << "," << a.se << " | " << b.fi << "," << b.se << el;
    // diag
    if (a.fi != b.fi && a.se != b.se)
    {
        g[a.fi][b.se] = '*';
        g[b.fi][a.se] = '*';
    }
    // hori
    else if (a.fi == b.fi)
    {
        if (a.fi > 0)
        {
            g[a.fi - 1][a.se] = '*';
            g[b.fi - 1][b.se] = '*';
        }
        else
        {
            g[a.fi + 1][a.se] = '*';
            g[b.fi + 1][b.se] = '*';
        }
    }
    // verti
    else if (a.se == b.se)
    {
        if (a.se > 0)
        {
            g[a.fi][a.se - 1] = '*';
            g[b.fi][b.se - 1] = '*';
        }
        else
        {
            g[a.fi][a.se + 1] = '*';
            g[b.fi][b.se + 1] = '*';
        }
    }
    print();
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