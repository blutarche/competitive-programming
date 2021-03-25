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

void solve()
{
  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < N / 2; i++)
  {
    char c1 = s[i];
    char c2 = s[N - i - 1];
    // cout << c1 << " " << c2 << endl;
    if (c1 != c2)
      cnt++;
  }
  int ans = 0;
  if (cnt < K)
    ans = K - cnt;
  else
    ans = cnt - K;
  // cout << cnt << endl;
  cout << ans << endl;
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