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
#define MOD 1000000007

#define mxN 200005

int d[mxN][10];

void precal()
{
  memset(d, 0, sizeof(d));
  forn(j, 10) d[0][j] = 1;
  forn(i, mxN - 1)
  {
    int idx = i + 1;
    forn(j, 10)
    {
      if (j == 9)
      {
        d[idx][j] = (d[idx - 1][0] + d[idx - 1][1]);
      }
      else
      {
        d[idx][j] = d[idx - 1][j + 1];
      }
      d[idx][j] %= MOD;
    }
  }
}

void solve()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int sum = 0;
  while (true)
  {
    int digit = n % 10;
    sum += d[m][digit];
    sum %= MOD;
    n /= 10;
    if (n == 0)
      break;
  }
  printf("%d\n", sum);

  // cout << "----" << el;
}

int main()
{
  precal();
  // forn(i, mxN)
  // {
  // forn(j, 10)
  // {
  //   cout << d[100][j] << " ";
  // }
  // cout << el;
  // }
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