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

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s[0] == '0' || s[n - 1] == '0')
  {
    cout << "NO" << el;
    return;
  }
  int c0 = 0, c1 = 0;
  string a = "", b = "";
  forn(i, n)
  {
    a.push_back('.');
    b.push_back('.');
    if (s[i] == '1')
      c1++;
    else
      c0++;
  }
  if (c0 % 2 != 0 || c1 % 2 != 0)
  {
    cout << "NO" << el;
    return;
  }
  int cc1 = 0, cc0 = 0;
  int ca = 0;
  int cb = 0;
  forn(i, n)
  {
    if (s[i] == '1')
    {
      if (cc1 < c1 / 2)
      {
        a[i] = '(';
        b[i] = '(';
        ca++;
        cb++;
      }
      else
      {
        a[i] = ')';
        b[i] = ')';
        ca--;
        cb--;
      }
      cc1++;
    }
    else
    {
      if (cc0 % 2 == 0)
      {
        a[i] = '(';
        b[i] = ')';
        ca++;
        cb--;
      }
      else
      {
        a[i] = ')';
        b[i] = '(';
        ca--;
        cb++;
      }
      cc0++;
    }
  }
  cout << "YES" << el;
  cout << a << el;
  cout << b << el;
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