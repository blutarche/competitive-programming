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

#define mxn 100005
int n;
vi v;
int dp[2][mxn];
int dp2[2][mxn];

int find_max()
{
  int maxlen = 2;
  int real_diff = v[1] - v[0];
  int replaced_diff = v[1] - v[0];
  int replaced_prev = v[1];
  int real_len = 2;
  int replaced_len = 2;
  for (int i = 2; i < n; i++)
  {
    int diff = v[i] - v[i - 1];
    if (v[i] == replaced_prev + replaced_diff)
    {
      replaced_len++;
      replaced_prev = v[i];
    }
    else
    {
      replaced_len = real_len + 1;
      replaced_diff = real_diff;
      replaced_prev = v[i - 1] + replaced_diff;
    }
    if (real_diff == diff)
    {
      real_len++;
    }
    else
    {
      real_len = 2;
      real_diff = diff;
    }
    if (replaced_len > maxlen)
    {
      maxlen = replaced_len;
    }
    if (real_len > maxlen)
    {
      maxlen = real_len;
    }
    // cout << v[i] << " = "
    //      << "real: " << real_diff << " " << real_len << " --- "
    //      << "replaced: " << replaced_diff << " " << replaced_len << ln;
  }
  return maxlen;
}

void solve()
{
  v.clear();
  memset(dp, 0, sizeof(0));
  memset(dp2, 0, sizeof(0));
  cin >> n;
  forn(i, n)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  int max1 = find_max();
  reverse(v.begin(), v.end());
  int max2 = find_max();
  if (max1 < max2)
  {
    cout << max2 << ln;
  }
  else
  {
    cout << max1 << ln;
  }
}

int main()
{
  fast_cin();
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  // solve();

  return 0;
}