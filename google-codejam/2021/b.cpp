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
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 1002

vi v;
int cost = 0;
ll dpc[mxN];
ll dpj[mxN];

void solve()
{
  memset(dpc, 0, sizeof(dpc));
  memset(dpj, 0, sizeof(dpj));
  int x, y;
  string s;
  cin >> x >> y;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'C')
    {
      dpj[i] = INF;
      if (i > 0)
      {
        dpc[i] = min(dpc[i - 1], dpj[i - 1] + y);
      }
      else
      {
        dpc[i] = 0;
      }
    }
    else if (s[i] == 'J')
    {
      dpc[i] = INF;
      if (i > 0)
      {
        dpj[i] = min(dpj[i - 1], dpc[i - 1] + x);
      }
      else
      {
        dpj[i] = 0;
      }
    }
    else
    {
      if (i > 0)
      {
        dpc[i] = min(dpc[i - 1], dpj[i - 1] + y);
        dpj[i] = min(dpj[i - 1], dpc[i - 1] + x);
      }
      else
      {
        dpj[i] = 0;
        dpc[i] = 0;
      }
    }
  }
  // for (int i = 0; i < s.length(); i++)
  // {
  //   cout << dpc[i] << " ";
  // }
  // cout << el;
  // for (int i = 0; i < s.length(); i++)
  // {
  //   cout << dpj[i] << " ";
  // }
  // cout << el;
  cout << min(dpc[s.length() - 1], dpj[s.length() - 1]) << el;
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