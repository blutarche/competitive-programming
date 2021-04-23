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
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pll>> vvll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
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
#define el endl;
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 200

int g[mxN][mxN];

void solve()
{

    memset(g, 0, sizeof(g));
    int n;
    cin >> n;
    forn(i, n)
    {
        forn(j, n)
        {
            cin >> g[i][j];
        }
    }
    int r = 0, c = 0, t = 0;
    forn(i, n)
    {
        bool ur[mxN], uc[mxN];
        memset(ur, 0, sizeof(ur));
        memset(uc, 0, sizeof(uc));
        bool uur = false, uuc = false;
        forn(j, n)
        {
            if (i == j)
            {
                t += g[i][j];
            }
            if (ur[g[i][j]])
            {
                uur = true;
            }
            if (uc[g[j][i]])
            {
                uuc = true;
            }
            ur[g[i][j]] = true;
            uc[g[j][i]] = true;
        }
        if (uur)
            r++;
        if (uuc)
            c++;
    }
    cout << t << " " << r << " " << c << el;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    return 0;
}