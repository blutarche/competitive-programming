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
ll g[302][302];
ll m[302][302];
typedef pair<ll, pair<int, int>> pp;
vector<pp> h;
priority_queue<pp> pq;

void ripple(int y, int x, ll h)
{
    if (y < 0 || y >= R || x < 0 || x >= C)
        return;
    if (g[y][x] > h)
        return;
    if (m[y][x] > h)
        return;
    m[y][x] = h;
    pq.push(make_pair(h - 1, make_pair(y - 1, x)));
    pq.push(make_pair(h - 1, make_pair(y + 1, x)));
    pq.push(make_pair(h - 1, make_pair(y, x - 1)));
    pq.push(make_pair(h - 1, make_pair(y, x + 1)));
    // ripple(y - 1, x, h - 1);
    // ripple(y + 1, x, h - 1);
    // ripple(y, x - 1, h - 1);
    // ripple(y, x + 1, h - 1);
}

void solve()
{
    // clear
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            m[i][j] = 0;
        }
    }
    pq = priority_queue<pp>();
    h.clear();

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> g[i][j];
            pp ppp = make_pair(g[i][j], make_pair(i, j));
            // h.push_back(ppp);
            pq.push(ppp);
        }
    }
    // sort(h.begin(), h.end(), greater<>());
    while (!pq.empty())
    {
        pp p = pq.top();
        pq.pop();
        pair<int, int> coor = p.second;
        // cout << coor.first << " " << coor.second << endl;
        if (p.first > m[coor.first][coor.second])
        {
            ripple(coor.first, coor.second, p.first);
        }
    }

    ll cnt = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (m[i][j] > g[i][j])
            {
                cnt += m[i][j] - g[i][j];
            }
            // cout << m[i][j] << " ";
        }
        // cout << endl;
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