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

#define mxn 101
#define mxa 2001
int n;
vpi v;
bool dp[mxn][mxn * mxa];
bool dp2[mxn][mxn * mxa];

void debug_dp(int sum)
{
  forn(i, v.size() + 1)
  {
    forn(j, sum + 1)
    {
      cout << dp[i][j] << " ";
    }
    cout << ln;
  }
  cout << "-----" << ln;
}
void generate_dp(int sum)
{
  memset(dp, false, sizeof(dp));
  for (int i = 0; i < v.size() + 1; i++)
  {
    dp[i][0] = true;
  }
  forn(idxi, v.size())
  {
    int i = idxi + 1;
    forn(idxj, sum)
    {
      int j = idxj + 1;
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i - 1].fi)
      {
        dp[i][j] = (dp[i][j] || dp[i - 1][j - v[i - 1].fi]);
      }
    }
  }
  // debug_dp(sum);
}

void generate_dp2(int sum)
{
  memset(dp2, false, sizeof(dp2));
  for (int i = 0; i < v.size() + 1; i++)
  {
    dp2[i][0] = true;
  }
  forn(idxi, v.size())
  {
    int i = idxi + 1;
    forn(idxj, sum)
    {
      int j = idxj + 1;
      dp2[i][j] = dp2[i - 1][j];
      if (j >= v[i - 1].fi)
      {
        dp2[i][j] = (dp2[i][j] || dp2[i - 1][j - v[i - 1].fi]);
      }
    }
  }
  // debug_dp(sum);
}

void solve()
{
  v.clear();
  cin >> n;
  int sum = 0;
  int odd = -1;
  forn(i, n)
  {
    int tmp;
    cin >> tmp;
    sum += tmp;
    if (tmp % 2 == 1)
    {
      odd = i;
    }
    v.push_back(mp(tmp, i));
  }
  if (sum % 2 == 1)
  {
    cout << 0 << ln;
    return;
  }
  if (odd != -1)
  {
    cout << 1 << ln;
    cout << odd + 1 << ln;
    return;
  }
  sort(v.begin(), v.end());

  sum = sum / 2;
  generate_dp(sum);

  vi r;

  while (true)
  {
    if (!dp[v.size()][sum])
      break;
    if (v.size() == 0)
      break;
    int idx = -1;
    forn(i, v.size())
    {
      pi p = v[i];
      int x = v[i].fi / 2;
      if (x % 2 == 1)
      {
        idx = i;
        break;
      }

      v.erase(v.begin() + i);
      generate_dp2(sum - x);
      if (!dp2[v.size()][sum - x])
      {
        idx = i;
        break;
      }
      v.insert(v.begin() + i, p);
    }
    if (idx != -1)
    {
      r.push_back(v[idx].se);
      break;
    }
    else
    {
      sum -= v[0].fi / 2;
      r.push_back(v[0].se);
      v.erase(v.begin());
      generate_dp(sum);
    }
  }
  cout << r.size() << ln;
  forn(i, r.size())
  {
    cout << r[i] + 1 << " ";
  }
  if (r.size() > 0)
  {
    cout << ln;
  }
  // cout << "=====" << ln;
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
  // }
  solve();

  return 0;
}