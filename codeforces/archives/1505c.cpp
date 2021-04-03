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
#define se second #define el endl
#define INF 2e18
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 100

void solve()
{
}

int main()
{
  string s;
  cin >> s;
  char p1 = s[0];
  char p2 = s[1];
  if (s.length() <= 2)
  {
    cout << "YES" << endl;
    return 0;
  }
  bool cor = true;
  forn(i, s.length() - 2)
  {
    int idx = i + 2;
    char c = s[idx];
    int n1 = p1 - 'A';
    int n2 = p2 - 'A';
    int n = (p1 + p2) % 26;
    // cout << "n:" << n << endl;
    char should = 'A' + n;
    // cout << p1 << " " << p2 << " = " << should << " -- " << c << endl;
    if (should != c)
    {
      cor = false;
      break;
    }
    p1 = p2;
    p2 = c;
  }
  if (cor)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}