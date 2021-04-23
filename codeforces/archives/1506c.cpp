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

void solve()
{
    string a, b;
    cin >> a;
    cin >> b;
    int lcs[31][31];
    int len = 0;
    int row, col;
    forn(i, a.length())
    {
        forn(j, b.length())
        {
            if (a[i] == b[j])
            {
                if (i == 0 || j == 0)
                {
                    lcs[i][j] = 1;
                }
                else
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                if (lcs[i][j] > len)
                {
                    len = lcs[i][j];
                }
            }
            else
            {
                lcs[i][j] = 0;
            }
        }
    }
    // forn(i, a.length())
    // {
    //     forn(j, b.length())
    //     {
    //         cout << lcs[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << len << " len" << endl;
    cout << a.length() + b.length() - len * 2 << endl;
}

int main()
{
    int t;
    cin >> t;
    forn(i, t)
    {
        solve();
    }
    return 0;
}