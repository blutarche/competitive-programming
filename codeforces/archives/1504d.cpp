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

#define mxN 102

int n;
int g[mxN][mxN];
bool inqueue[mxN][mxN];
vector<pii> v;

bool eligible(int y, int x, int num)
{
    int u = g[y - 1][x];
    int d = g[y + 1][x];
    int l = g[y][x - 1];
    int r = g[y][x + 1];
    int ul = g[y - 1][x - 1];
    int ur = g[y - 1][x + 1];
    int dl = g[y + 1][x - 1];
    int dr = g[y + 1][x + 1];
    bool uul = ul == 0 || num == ul;
    bool uur = ur == 0 || num == ur;
    bool udl = dl == 0 || num == dl;
    bool udr = dr == 0 || num == dr;
    return uul && uur && udl && udr && u != num && d != num && l != num && r != num;
}

bool passable(int y, int x, int num)
{
    int u = g[y - 1][x];
    int d = g[y + 1][x];
    int l = g[y][x - 1];
    int r = g[y][x + 1];
    return u != num && d != num && l != num && r != num;
}

int find(int num)
{
    int i = 0;
    for (pii p : v)
    {
        if (eligible(p.first, p.second, num))
        {
            return i;
        }
        i++;
    }
    return -1;
}

void debug()
{
    cout << "--------------" << el;
    cout << "v ==> ";
    for (pii p : v)
    {
        cout << p.first << "|" << p.second << " ";
    }
    cout << el;
    cout << "g:" << el;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j])
            {
                cout << g[i][j];
            }
            else
            {
                cout << '.';
            }
        }
        cout << el;
    }
    cout << "==============" << el;
}

void insert_to_q(int y, int x)
{
    if (g[y][x] == 0 && 1 <= y && y <= n && 1 <= x && x <= n && !inqueue[y][x])
    {
        v.push_back(mp(y, x));
        inqueue[y][x] = true;
    }
}

void insert(int y, int x, int num)
{
    cout << num << " " << y << " " << x << " " << el;
    cout.flush();
    g[y][x] = num;
    inqueue[y][x] = true;
    insert_to_q(y + 1, x);
    insert_to_q(y - 1, x);
    insert_to_q(y, x + 1);
    insert_to_q(y, x + 1);
    insert_to_q(y + 1, x + 1);
    insert_to_q(y + 1, x - 1);
    insert_to_q(y - 1, x + 1);
    insert_to_q(y - 1, x - 1);
}

void solve(int ex)
{
    // debug();
    int a = (ex) % 3 + 1;
    int b = (ex + 1) % 3 + 1;
    // cout << "a:" << a << " "
    //            << "b:" << b << el;
    int pa = find(a);
    int pb = find(b);
    // cout << "pa:" << pa << " "
    //            << "pb:" << pb << el;
    if (pa != -1)
    {
        insert(v[pa].first, v[pa].second, a);
        v.erase(v.begin() + pa);
    }
    else if (pb != -1)
    {
        insert(v[pb].first, v[pb].second, b);
        v.erase(v.begin() + pb);
    }
    else
    {
        int idx = 0;
        bool non_passed = true;
        for (pii p : v)
        {
            if (passable(p.first, p.second, a))
            {
                insert(p.first, p.second, a);
                v.erase(v.begin() + idx);
                non_passed = false;
                break;
            }
            else if (passable(p.first, p.second, b))
            {
                insert(p.first, p.second, b);
                v.erase(v.begin() + idx);
                non_passed = false;
                break;
            }
            idx++;
        }
        if (non_passed)
        {
            cout << "FUCKED" << el;
            exit(1);
        }
    }
    // debug();
}

int main()
{
    memset(g, 0, sizeof(g));
    memset(inqueue, false, sizeof(inqueue));
    cin >> n;
    int size = n * n;
    v.push_back(mp(1, 1));
    forn(i, size)
    {
        int t;
        cin >> t;
        solve(t);
    }

    return 0;
}