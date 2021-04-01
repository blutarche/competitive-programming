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
#define se second
#define el endl;
#define INF 2e18
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 200

vi v;
int cost = 0;
int g[mxN];

void rev(int i, int j)
{
  int a = i, b = j;
  while (a < b)
  {
    int tmp = g[a];
    g[a] = g[b];
    g[b] = tmp;
    a++;
    b--;
  }
}

void solve()
{
  v.clear();
  int n, c;
  cin >> n;
  cin >> c;
  if (c < n - 1)
  {
    cout << "IMPOSSIBLE" << el;
    return;
  }

  forn(i, n) g[i] = i + 1;

  c -= n - 1;
  vii v;
  int i = 0;
  forn(i, n - 1)
  {
    if (c > 0)
    {
      int j;
      if (n - 1 - i < c)
      {
        j = n - 1;
      }
      else
      {
        j = i + c;
      }
      c -= j - i;
      v.push_back(mp(i, j));
    }
    else
    {
      break;
    }
  }
  if (c > 0)
  {
    cout << "IMPOSSIBLE" << el;
    return;
  }
  sort(v.begin(), v.end(), greater<pii>());
  bool r = false;
  for (pii p : v)
  {
    // cout << p.first << " " << p.second << el;
    // forn(i, n)
    // {
    //   cout << g[i];
    //   if (i < n - 1)
    //     cout << " ";
    // }
    // cout << el;
    rev(p.first, p.second);
  }

  forn(i, n)
  {
    cout << g[i];
    if (i < n - 1)
      cout << " ";
  }
  cout << el;
  // cout << "-----" << el;
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