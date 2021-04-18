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
int n;
vi v0, v1;

void solve()
{
  v0.clear();
  v1.clear();
  cin >> n;
  forn(i, n)
  {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0)
    {
      v0.push_back(tmp);
    }
    else
    {
      v1.push_back(tmp);
    }
  }
  if (v0.size() > v1.size())
  {
    for (int x : v0)
    {
      cout << x << " ";
    }
    for (int x : v1)
    {
      cout << x << " ";
    }
  }
  else
  {
    for (int x : v1)
    {
      cout << x << " ";
    }
    for (int x : v0)
    {
      cout << x << " ";
    }
  }
  cout << ln;
}

int main()
{
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