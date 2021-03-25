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

void solve()
{
  int n;
  cin >> n;
  map<int, int> m;
  forn(i, n)
  {
    int a;
    cin >> a;
    m[a]++;
  }
  vector<p32> v;
  for (auto it : m)
  {
    v.push_back(make_pair(-it.second, it.first));
  }
  sort(v.begin(), v.end());
  // for (p32 p : v)
  // {
  //   cout << p.first << "\t" << p.second << endl;
  // }
  int a = 0, b = 0;
  for (p32 p : v)
  {
    int diff = abs(a - b);
    int x = abs(p.first);
    // cout << "x: " << x << " diff: " << diff << endl;
    if (diff <= x)
    {
      if (a < b)
        a = b;
      else
        b = a;
      x -= diff;
      int fora = min(a / 2, x / 2);
      a += fora;
      b += x - fora;
    }
    else
    {
      if (a < b)
      {
        a += x;
      }
      else
      {
        b += x;
      }
    }
    // cout << a << " " << b << endl;
  }
  cout << abs(a - b) << endl;
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