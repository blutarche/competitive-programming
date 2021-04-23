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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
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
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int R, C;
bool g[1002][1002];

int calc(int y, int x)
{
    int cnt = 0;
    for (int i = 2, j = 4; i <= y && j <= x; i += 1, j += 2)
    {
        cnt++;
    }

    for (int i = 4, j = 2; i <= y && j <= x; i += 2, j += 1)
    {
        cnt++;
    }

    return cnt;
}

int downRight(int y, int x)
{
    int i = y + 1;
    while (i <= R && g[i][x])
    {
        ++i;
    }
    int yy = i - y;

    int j = x + 1;
    while (j <= C && g[y][j])
    {
        ++j;
    }
    int xx = j - x;

    return calc(yy, xx);
}

int upRight(int y, int x)
{
    int i = y - 1;
    while (i >= 1 && g[i][x])
    {
        --i;
    }
    int yy = y - i;

    int j = x + 1;
    while (j <= C && g[y][j])
    {
        ++j;
    }
    int xx = j - x;

    return calc(yy, xx);
}

int upLeft(int y, int x)
{
    int i = y - 1;
    while (i >= 1 && g[i][x])
    {
        --i;
    }
    int yy = y - i;

    int j = x - 1;
    while (j >= 1 && g[y][j])
    {
        --j;
    }
    int xx = x - j;

    return calc(yy, xx);
}

int downLeft(int y, int x)
{
    int i = y + 1;
    while (i <= R && g[i][x])
    {
        ++i;
    }
    int yy = i - y;

    int j = x - 1;
    while (j >= 1 && g[y][j])
    {
        --j;
    }
    int xx = x - j;

    return calc(yy, xx);
}

void solve()
{
    cin >> R >> C;
    for (int i = 0; i <= R + 1; i++)
    {
        for (int j = 0; j <= C + 1; j++)
        {
            g[i][j] = false;
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                g[i][j] = true;
            }
            else
            {
                g[i][j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (!g[i][j])
                continue;
            int dr = downRight(i, j);
            int dl = downLeft(i, j);
            int ul = upLeft(i, j);
            int ur = upRight(i, j);
            cnt += dr + dl + ul + ur;
            // cout << i << " " << j << " | " << dr << " " << dl << " " << ul << " " << ur << endl;
        }
    }
    cout << cnt << endl;
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