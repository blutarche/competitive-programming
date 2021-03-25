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
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 200002

void solve()
{
  int n;
  cin >> n;
  int last = -1;
  vector<int> min, max;
  bool minu[mxN], maxu[mxN];
  forn(i, n + 2)
  {
    minu[i] = false;
    maxu[i] = false;
  }
  int curmin = 1, curmax = n;
  forn(i, n)
  {
    int a;
    cin >> a;
    if (last != a)
    {
      min.push_back(a);
      max.push_back(a);
      minu[a] = true;
      maxu[a] = true;
      curmax = a - 1;
    }
    else
    {
      while (minu[curmin])
      {
        curmin++;
      }
      min.push_back(curmin);
      minu[curmin] = true;
      while (maxu[curmax])
      {
        curmax--;
      }
      max.push_back(curmax);
      maxu[curmax] = true;
    }
    last = a;
  }
  int i = 0;
  for (int a : min)
  {
    cout << a;
    if (i + 1 < min.size())
      cout << " ";
    i++;
  }
  cout << endl;
  i = 0;
  for (int a : max)
  {
    cout << a;
    if (i + 1 < min.size())
      cout << " ";
    i++;
  }
  cout << endl;
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