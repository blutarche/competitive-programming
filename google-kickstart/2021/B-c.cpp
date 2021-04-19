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
ll z;
vl v;

bool check_prime(ll x)
{
  if (x == 1)
    return false;
  if (x == 2)
    return true;
  if (x % 2 == 0)
    return false;
  for (ll i = 3; i * i <= x; i += 2)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

void find_most_closest_prime(ll x)
{
  int lower = 10;
  for (ll i = x; i >= 2; i--)
  {
    if (lower == 0)
      break;
    if (check_prime(i))
    {
      v.push_back(i);
      lower--;
    }
  }

  int upper = 10;
  for (ll i = x + 1; upper > 0; i++)
  {
    if (upper == 0)
      break;
    if (check_prime(i))
    {
      v.push_back(i);
      upper--;
    }
  }
}

void solve()
{
  cin >> z;
  ll sq = (ll)sqrtl(z);
  v.clear();
  find_most_closest_prime(sq);
  sort(v.begin(), v.end());
  // for (ll x : v)
  // {
  //   cout << x << " ";
  // }
  ll max = -1;
  for (int i = 0; i < v.size() - 1; i++)
  {
    ll x = v[i] * v[i + 1];
    if (x > max && x <= z)
    {
      max = x;
    }
  }
  cout << max << ln;
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