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

#define mxN 5000
int n, l, r, s;
int a[mxN];
bool used[mxN];

void print()
{
  forn(i, n)
  {
    cout << a[i] << " ";
  }
  cout << el;
}

bool check_eligible()
{
  int sum = 0;
  forn(i, n)
  {
    if (a[i] < 1 || n < a[i])
      return false;
    if (l <= i && i <= r)
      sum += a[i];
  }
  if (sum != s)
    return false;
  return true;
}

int psb(int max, int cnt)
{
  return cnt * (cnt + 1) / 2 + (max - cnt) * cnt;
}

void fill()
{
  vi v;
  int sum = 0;
  int curmax = n;
  for (int idx = l; idx <= r; idx++)
  {
    int cnt = r - idx;
    int psb = cnt * (cnt + 1) / 2;
    while (sum + curmax + psb > s)
      curmax--;
    a[idx] = curmax;
    used[curmax] = true;
    sum += curmax;
    curmax--;
  }
  // print();
}

void solve()
{
  memset(a, 0, sizeof(a));
  memset(used, false, sizeof(used));
  cin >> n >> l >> r >> s;
  --l;
  --r;
  fill();
  // print();
  int y = 1;
  forn(i, n)
  {
    if (a[i] == 0)
    {
      while (used[y])
        y++;
      a[i] = y;
      used[y] = true;
    }
  }
  if (!check_eligible())
  {
    cout << "-1" << el;
  }
  else
  {
    print();
  }
  // cout << "---" << el;
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