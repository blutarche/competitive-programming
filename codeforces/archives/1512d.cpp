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

#define mxN 200005
int n;
vl b;
ll mx1 = 0, mx2 = 0;
int mxpos1 = -1, mxpos2 = -1;
ll sum = 0;

int try_pos_as_sum(int pos)
{
    ll s = sum - b[pos];
    forn(i, n + 2)
    {
        if (i != pos)
        {
            if (s - b[i] == b[pos])
            {
                return i;
            }
        }
    }
    return -1;
}

void print_ans(int pos1, int pos2)
{
    forn(i, n + 2)
    {
        if (i != pos1 && i != pos2)
        {
            cout << b[i] << " ";
        }
    }
    cout << el;
    // cout << b[pos1] << " " << b[pos2] << el;
}

void solve()
{
    b.clear();
    cin >> n;
    mx1 = 0, mx2 = 0;
    mxpos1 = -1, mxpos2 = -1;
    sum = 0;
    forn(i, n + 2)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
        sum += tmp;
        if (mx1 < tmp)
        {
            mx2 = mx1;
            mxpos2 = mxpos1;
            mx1 = tmp;
            mxpos1 = i;
        }
        else if (mx2 < tmp)
        {
            mx2 = tmp;
            mxpos2 = i;
        }
    }
    // cout << mx1 << " " << mx2 << el;
    int pos2;
    pos2 = try_pos_as_sum(mxpos1);
    if (pos2 != -1)
    {
        print_ans(mxpos1, pos2);
        return;
    }
    pos2 = try_pos_as_sum(mxpos2);
    if (pos2 != -1)
    {
        print_ans(mxpos2, pos2);
        return;
    }
    cout << "-1" << el;
    // cout << "---" << el;
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