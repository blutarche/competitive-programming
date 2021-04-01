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

#define mxP 100
#define mxQ 10000

#define pli pair<ld, int>

bool p[mxP][mxQ];
ld skill[mxP];
ld difc[mxQ];
map<ll, ld> pp;
map<ll, ld> pq;

ld prob_to_solve(ld S, ld Q)
{
  return 1.0 / (1.0 + exp(-1 * (S - Q)));
}

ld prob_to_cheat(ld S, ld Q)
{
  return 0.5 + prob_to_solve(S, Q) * 0.5;
}

ld difficulty_score(ld freq)
{
  return 6 * (mxP - freq) / mxP - 3;
}

ld skill_score(ld score)
{
  return 6 * (mxQ - score) / mxQ - 3;
}

int find_cheater()
{
  vector<pli> v;
  forn(i, mxP)
  {
    ld cheat = 1;
    ld real = 0;
    forn(j, mxQ)
    {
      ld df = difficulty_score(pq[j]);
      if (p[i][j])
      {
        cheat *= prob_to_cheat(0, df);
        // real += prob_to_solve(0, df);
      }
      else
      {
        cheat *= 0.5 * (1 - prob_to_solve(0, df));
        // real -= 0.5
      }
      cheat *= 2;
    }
    v.push_back(mp(cheat, i + 1));
  }
  sort(all(v), greater<pli>());
  // for (pli p : v)
  // {
  //   cout << p.first << " | " << p.second << el;
  // }
  return v[0].second;
}

void solve()
{
  memset(p, 0, sizeof(p));
  pp.clear();
  pq.clear();

  forn(i, mxP)
  {
    string s;
    cin >> s;
    int sum = 0;
    int j = 0;
    for (char c : s)
    {
      if (c == '1')
      {
        pq[j]++;
        p[i][j] = true;
        sum++;
      }
      else
      {
        p[i][j] = false;
      }
      j++;
    }
    pp[i] = sum;
  }

  int cheater = find_cheater();
  cout << cheater << el;
}

int main()
{
  int T;
  cin >> T;

  double P;
  cin >> P;
  for (int i = 0; i < T; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }

  return 0;
}