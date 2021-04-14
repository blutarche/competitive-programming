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
#define INF 2e18
ll MOD = 998244353;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxn 300005
int r, c;
ll val[mxn];

ll w;

void solve()
{
  cin >> r >> c;
  char g[r][c];
  ll dpred[r][c];
  ll dpblue[r][c];
  memset(g, 0, sizeof(g));
  memset(dpred, 0, sizeof(dpred));
  memset(dpblue, 0, sizeof(dpblue));
  forn(i, r)
  {
    string s;
    cin >> s;
    forn(j, c)
    {
      g[i][j] = s[j];
      if (s[j] == 'o')
        w++;
    }
  }

  ll sum = 0;

  // red
  forn(i, r)
  {
    forn(j, c - 1)
    {
      int idx = j + 1;
      if (g[i][idx] != 'o' || g[i][idx - 1] != 'o')
        continue;
      ll dp;
      dp = val[w - 2] - dpred[i][idx - 1] / 2;
      dpred[i][idx] = dp;
      sum += dp;
      sum %= MOD;
      // cout << sum << ln;
    }
  }

  // blue
  forn(j, c)
  {
    forn(i, r - 1)
    {
      if (g[i][j] != 'o' || g[i + 1][j] != 'o')
        continue;
      ll dp;
      dp = val[w - 2];
      if (i > 0)
      {
        dp -= dpblue[i - 1][j] / 2;
      }
      dpblue[i][j] = dp;
      sum += dp;
      sum %= MOD;
      // cout << sum << ln;
    }
  }

  forn(i, r)
  {
    forn(j, c)
    {
      cout << dpred[i][j] << " ";
    }
    cout << ln;
  }

  forn(i, r)
  {
    forn(j, c)
    {
      cout << dpblue[i][j] << " ";
    }
    cout << ln;
  }

  cout << sum << ln;
}

int main()
{
  ll x = 1;
  forn(i, mxn)
  {
    val[i] = x;
    x *= 2;
    x %= MOD;
  }
  fast_cin();
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