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
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 402
int n;

void solve()
{
  int a, b;
  int ta, tb;
  cin >> a >> b;
  ta = a;
  tb = b;
  string s;
  cin >> s;
  // fill in the known
  forn(i, s.length() / 2)
  {
    int j = s.length() - i - 1;
    if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
    {
      cout << "-1" << el;
      return;
    }
    if (s[i] == '1' || s[j] == '1')
    {
      s[i] = '1';
      s[j] = '1';
      b -= 2;
    }
    else if (s[i] == '0' || s[j] == '0')
    {
      s[i] = '0';
      s[j] = '0';
      a -= 2;
    }
  }
  if (s.length() % 2 == 1)
  {
    int mid = s.length() / 2;
    if (s[mid] == '1')
    {
      b--;
    }
    else if (s[mid] == '0')
    {
      a--;
    }
  }
  // cout << a << " " << b << el;
  // fill in the unknown
  forn(i, s.length() / 2)
  {
    int j = s.length() - i - 1;
    if (s[i] == '?' && s[j] == '?')
    {
      if (a >= 2)
      {
        s[i] = '0';
        s[j] = '0';
        a -= 2;
      }
      else
      {
        s[i] = '1';
        s[j] = '1';
        b -= 2;
      }
    }
  }
  if (s.length() % 2 == 1)
  {
    int mid = s.length() / 2;
    if (s[mid] == '?')
    {
      if (a > 0)
      {
        s[mid] = '0';
        a--;
      }
      else
      {
        s[mid] = '1';
        b--;
      }
    }
  }
  // cout << "s:" << s << el;
  forn(i, s.length())
  {
    if (s[i] == '0')
      ta--;
    else
      tb--;
  }
  if (ta != 0 || tb != 0)
  {
    cout << "-1" << el;
  }
  else
  {
    cout << s << el;
  }
  // cout << "-------" << el;
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