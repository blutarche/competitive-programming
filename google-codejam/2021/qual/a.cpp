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

vi v;
int cost = 0;

void rev(int i, int j)
{
    int a = i, b = j;
    while (a < b)
    {
        int tmp = v[a];
        v[a] = v[b];
        v[b] = tmp;
        a++;
        b--;
    }
    cost += j - i + 1;
}

void solve()
{
    v.clear();
    int n;
    cin >> n;
    forn(i, n)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cost = 0;
    forn(i, v.size() - 1)
    {
        int minpos = 0;
        int min = 99999;
        int j = i;
        for (j = i; j < v.size(); j++)
        {
            if (v[j] < min)
            {
                minpos = j;
                min = v[j];
            }
        }
        rev(i, minpos);
        // for (int x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << el;
    }
    cout << cost << el;
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