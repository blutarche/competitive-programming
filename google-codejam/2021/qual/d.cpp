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

#define DEBUG false

#define mxN 51
int N, Q;
vi v;
int cache[mxN][mxN][mxN];

int ask(int a, int b, int c)
{
  if (cache[a][b][c] != -1)
    return cache[a][b][c];
  cout << a << " " << b << " " << c << el;
  int med;
  cin >> med;
  cache[a][b][c] = med;
  if (med == -1)
  {
    exit(1);
  }
  return med;
}

int answer()
{
  if (DEBUG)
  {
    cout << "ans: ";
  }
  for (int x : v)
  {
    cout << x << " ";
  }
  cout << el;
  int tmp;
  if (!DEBUG)
  {
    cin >> tmp;
  }
  return tmp;
}

int bina(int l, int r, int cur)
{
  if (l >= r)
  {
    return l;
  }
  int mid = l + (r - l + 1) / 3;
  int mid2 = l + (2.0 * (r - l + 1) / 3);
  if (DEBUG)
  {
    cout << l << " | " << mid << " : " << mid2 << " | " << r << el;
  }
  if (mid >= mid2)
    return mid;
  int med = ask(v[mid], v[mid2], cur);
  if (med == cur)
  {
    if (mid + 1 == mid2)
    {
      return mid + 1;
    }
    return bina(mid, mid2, cur);
  }
  else if (med == v[mid])
  {
    if (mid == 0)
      return -1;
    return bina(l, mid, cur);
  }
  else if (med == v[mid2])
  {
    if (mid2 == r)
      return r + 1;
    return bina(mid2, r, cur);
  }
  return -1;
}

void solve()
{
  memset(cache, -1, sizeof(cache));
  v.clear();
  int med = ask(1, 2, 3);
  if (med == 1)
  {
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
  }
  else if (med == 2)
  {
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
  }
  else if (med == 3)
  {
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
  }
  // answer();
  int cur = 4;
  while (cur <= N)
  {
    // int med = ask(v[0], v[v.size() - 1], cur);
    int pos = bina(0, v.size() - 1, cur);
    if (DEBUG)
    {
      cout << "pos: " << pos << ":" << v.size() << el;
    }
    if (pos <= -1)
    {
      v.insert(v.begin(), cur);
    }
    else if (pos >= v.size())
    {
      v.push_back(cur);
    }
    else
    {
      v.insert(v.begin() + pos, cur);
    }
    cur++;
    if (DEBUG)
    {
      answer();
    }
  }
  int ans = answer();
  if (ans == -1)
  {
    exit(0);
  }
}

int main()
{
  int T, Q;
  cin >> T >> N >> Q;
  for (int i = 0; i < T; i++)
  {
    // cout << "Case #" << i + 1 << ": ";
    solve();
  }

  return 0;
}