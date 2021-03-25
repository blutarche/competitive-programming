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

#define MXN 502
#define MXK 20

int N;
int a[MXN][MXN];
int b[MXN][MXN];
int r[MXN], c[MXN];

#define bit0 1
#define bit1 0
#define undefbit 2
// [0]=1, [1]=0, [2]=-1
int dp[MXN][MXN][MXK];

void input()
{
  cin >> N;
  // a
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> a[i][j];
    }
  }
  // b
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> b[i][j];
    }
  }
  // r
  for (int i = 0; i < N; i++)
  {
    cin >> r[i];
  }
  // c
  for (int i = 0; i < N; i++)
  {
    cin >> c[i];
  }
}

void reset()
{
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  memset(dp, 0, sizeof(dp));
}

void solve()
{
  reset();
  input();
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N * N; k++)
      {
        int nextdpy = -1;
        if (i - 1 >= 0)
        {
          nextdpy = dp[i - 1][j][k];
        }
        int nextdpx = -1;
        if (j - 1 >= 0)
        {
          nextdpx = dp[i][j - 1][k];
        }
        int nextdp;
        if (nextdpy == -1)
        {
          nextdp = nextdpx;
        }
        if (nextdpx == -1)
        {
          nextdp = nextdpy;
        }
        if (nextdpx >= 0 && nextdpy >= 0)
        {
          nextdp = min(nextdpx, nextdpy);
        }
        if (a[i][j] == -1)
        {
          if (nextdp >= 0)
          {
            dp[i][j][k + 1] = nextdp + b[i][j];
          }
          else
          {
            dp[i][j][k + 1] = b[i][j];
          }
        }
        if (nextdp >= 0)
        {
          dp[i][j][k + 1] = nextdp;
        }
        else
        {
          dp[i][j][k] = 0;
        }
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N * N; k++)
      {
        cout << dp[i][j][k] << "|";
      }
      cout << "\t";
    }
    cout << endl;
  }
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