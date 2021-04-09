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
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 300001

bool g[mxN];
string a, b;

void flip(int idx)
{
  if (a[idx] == '0')
    a[idx] = '1';
  else
    a[idx] = '0';
}

void solve()
{
  memset(g, false, sizeof(g));
  int n;
  cin >> n;
  cin >> a;
  cin >> b;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == '0')
      c0++;
    else
      c1++;
    if (i % 2 == 1)
    {
      if (c0 == c1)
        g[i] = true;
    }
  }

  bool f = false;

  for (int i = n - (n % 2) - 1; i > 0; i -= 2)
  {
    if (f)
    {
      flip(i);
      flip(i - 1);
    }
    if (a[i] != b[i] && g[i])
    {
      f = !f;
      flip(i);
      flip(i - 1);
    }
    // cout << i << " : " << a << " | " << b << el;
  }

  bool can = true;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
    {
      can = false;
      break;
    }
  }
  if (can)
  {
    cout << "YES" << el;
  }
  else
  {
    cout << "NO" << el;
  }
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

  return 0;
}