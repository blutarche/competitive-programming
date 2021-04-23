#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pl>> vvpl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;

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
#define INF 1000000000
ll MOD = 998244353;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxn 502
#define mxk 21

bool __DEBUG__ = false;

int n, m, k;
map<pair<pi, pi>, int> mapp;
int g[mxn][mxn];
int dp[mxn][mxn];
int iterations = 0;

void input()
{
  cin >> n >> m >> k;
  forn(i, n)
  {
    forn(j, m - 1)
    {
      int tmp;
      cin >> tmp;
      mapp[mp(mp(i, j), mp(i, j + 1))] = tmp;
      mapp[mp(mp(i, j + 1), mp(i, j))] = tmp;
    }
  }
  forn(i, n - 1)
  {
    forn(j, m)
    {
      int tmp;
      cin >> tmp;
      mapp[mp(mp(i, j), mp(i + 1, j))] = tmp;
      mapp[mp(mp(i + 1, j), mp(i, j))] = tmp;
    }
  }
}

int get_map_val(int y, int x, int y2, int x2)
{
  pair<pi, pi> key = mp(mp(y, x), mp(y2, x2));
  if (mapp.find(key) != mapp.end())
    return mapp[key];
  return -1;
}

int find_min_next(int y, int x)
{
  int up = INF, down = INF, left = INF, right = INF;

  if (y > 0)
  {
    up = get_map_val(y, x, y - 1, x);
  }

  // down
  if (y < n - 1)
  {
    down = get_map_val(y, x, y + 1, x);
  }

  // left
  if (x > 0)
  {
    left = get_map_val(y, x, y, x - 1);
  }

  // right
  if (x < m - 1)
  {
    right = get_map_val(y, x, y, x + 1);
  }

  return min(min(min(up, down), left), right);
}

int solve_pt(int sty, int stx)
{
  memset(dp, 0, sizeof(dp));
  bool used[mxn][mxn];
  memset(used, false, sizeof(used));
  if (k % 2 != 0)
    return -1;

  if (__DEBUG__)
  {
    printf("start: (%d,%d) \n", sty, stx);
  }

  map<pi, bool> s;
  s[mp(sty, stx)] = true;
  used[sty][stx] = true;

  // repeat same place
  int minans = k * find_min_next(sty, stx);

  forn(kk, k / 2)
  {
    int move = kk + 1;
    map<pi, bool> s2;
    for (auto p : s)
    {
      iterations++;
      int y = p.fi.fi, x = p.fi.se;
      int dist = abs(sty - y) + abs(stx - x);
      if (dist != 0 && dp[y][x] != 0)
      {
        int value = dp[y][x] * 2;
        int repeat_times = k - 2 * dist;
        value += repeat_times * find_min_next(y, x);
        if (value != 0)
        {
          if (value < minans || minans == -1)
            minans = value;
        }
      }
      // up
      if (y > 0)
      {
        int val = get_map_val(y, x, y - 1, x);
        if (dp[y - 1][x] != 0)
        {
          dp[y - 1][x] = min(dp[y - 1][x], dp[y][x] + val);
        }
        else
        {
          dp[y - 1][x] = dp[y][x] + val;
        }
        if (!used[y - 1][x])
        {
          used[y - 1][x] = true;
          s2[mp(y - 1, x)] = true;
        }
      }

      // down
      if (y < n - 1)
      {
        int val = get_map_val(y, x, y + 1, x);
        if (dp[y + 1][x] != 0)
        {
          dp[y + 1][x] = min(dp[y + 1][x], dp[y][x] + val);
        }
        else
        {
          dp[y + 1][x] = dp[y][x] + val;
        }
        if (!used[y + 1][x])
        {
          used[y + 1][x] = true;
          s2[mp(y + 1, x)] = true;
        }
      }

      // left
      if (x > 0)
      {
        int val = get_map_val(y, x, y, x - 1);
        if (dp[y][x - 1] != 0)
        {
          dp[y][x - 1] = min(dp[y][x - 1], dp[y][x] + val);
        }
        else
        {
          dp[y][x - 1] = dp[y][x] + val;
        }
        if (!used[y][x - 1])
        {
          used[y][x - 1] = true;
          s2[mp(y, x - 1)] = true;
        }
      }

      // right
      if (x < m - 1)
      {
        int val = get_map_val(y, x, y, x + 1);
        if (dp[y][x + 1] != 0)
        {
          dp[y][x + 1] = min(dp[y][x + 1], dp[y][x] + val);
        }
        else
        {
          dp[y][x + 1] = dp[y][x] + val;
        }
        if (!used[y][x + 1])
        {
          used[y][x + 1] = true;
          s2[mp(y, x + 1)] = true;
        }
      }
    }

    s = s2;
  }

  for (auto p : s)
  {
    iterations++;
    int y = p.fi.fi, x = p.fi.se;
    int dist = abs(sty - y) + abs(stx - x);
    if (dist != 0 && dp[y][x] != 0)
    {
      int value = dp[y][x] * 2;
      int repeat_times = k - 2 * dist;
      value += repeat_times * find_min_next(y, x);
      if (value != 0)
      {
        if (value < minans || minans == -1)
          minans = value;
      }
    }
  }

  if (__DEBUG__)
  {
    forn(i, n)
    {
      forn(j, m)
      {
        cout << dp[i][j] << " ";
      }
      cout << ln;
    }
    cout << "-----" << ln;
  }
  return minans;
}

void solve()
{
  mapp.clear();
  memset(dp, 0, sizeof(dp));
  memset(g, 0, sizeof(g));
  input();
  forn(i, n)
  {
    forn(j, m)
    {
      g[i][j] = solve_pt(i, j);
      if (__DEBUG__)
      {
        cout << g[i][j] << " ";
      }
    }
    if (__DEBUG__)
    {
      cout << ln;
    }
    // cout << "it:" << iterations << ln;
  }

  forn(i, n)
  {
    forn(j, m)
    {
      cout << g[i][j] << " ";
    }
    cout << ln;
  }
}

int main()
{
  fast_cin();
  // int T;
  // cin >> T;
  // for (int i = 0; i < T; i++)
  // {
  //   // cout << "Case #" << i + 1 << ": ";
  //   solve();
  //   if (__DEBUG__)
  //   {
  //     cout << "=======" << ln;
  //   }
  // }
  solve();

  return 0;
}