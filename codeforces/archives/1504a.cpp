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

#define mxN 100

bool is_palin(string s)
{
  int mid = s.length() / 2;
  forn(j, mid)
  {
    int k = s.length() - 1 - j;
    if (s[j] != s[k])
      return false;
  }
  return true;
}

void solve()
{
  int n;
  cin >> n;
  forn(i, n)
  {
    string s;
    cin >> s;
    int mid = s.length() / 2;
    bool allA = true;
    forn(j, s.length())
    {
      if (s[j] != 'a')
      {
        allA = false;
      }
    }
    bool inserted = false;
    forn(j, mid)
    {
      int k = s.length() - 1 - j;
      if (s[j] == s[k] && s[j] != 'a')
      {
        s.insert(j, "a");
        inserted = true;
        break;
      }
    }
    if (!inserted)
    {
      s.insert(mid, "a");
    }
    if (is_palin(s))
    {
      cout << "NO" << el;
    }
    else
    {
      cout << "YES" << el;
      cout << s << el;
    }
  }
}

int main()
{
  // int T;
  // cin >> T;
  // for (int i = 0; i < T; i++)
  // {
  //   cout << "Case #" << i + 1 << ": ";
  //   solve();
  // }
  solve();

  return 0;
}