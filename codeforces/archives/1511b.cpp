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

#define mxn 100
int a, b, c;
ll prime[11];

void solve()
{
  cin >> a >> b >> c;
  ll cc = prime[c];
  ll aa;
  ll bb;
  forn(i, 10)
  {
    ll tmpa = cc * prime[i + 1];
    if (to_string(tmpa).length() == a)
    {
      aa = tmpa;
      break;
    }
  }
  forn(i, 10)
  {
    ll tmpb = cc * prime[i + 1];
    if (to_string(tmpb).length() == b)
    {
      bb = tmpb;
      break;
    }
  }
  if (aa == bb)
  {
    aa += cc;
  }

  cout << aa << " " << bb << ln;
}

int main()
{
  forn(x, 10)
  {
    ll xx = -1;
    for (ll i = pow(10, x) + 1;; i += 2)
    {
      bool none = true;
      for (ll j = 3; j * j <= i; j += 2)
      {
        if (i % j == 0)
        {
          none = false;
          break;
        }
      }
      if (none)
      {
        xx = i;
        break;
      }
    }
    prime[x + 1] = xx;
  }
  // forn(x, 9)
  // {
  //   cout << prime[x] << ln;
  // }
  fast_cin();
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