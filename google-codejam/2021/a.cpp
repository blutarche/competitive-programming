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
#define el endl
#define INF 2e18
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxN 100

void solve()
{
    int n;
    cin >> n;
    ll prev = -1;
    ll ans = 0;
    forn(i, n)
    {
        ll tmp;
        ll ans_round = 0;
        cin >> tmp;
        if (tmp > prev)
        {
            // cout << tmp << el;
            prev = tmp;
            continue;
        }
        string a = to_string(tmp);
        string b = to_string(prev);
        bool mismatched = false;
        int mispos = 0;
        forn(j, b.length())
        {
            if (j < a.length() && a[j] != b[j])
            {
                mismatched = true;
                mispos = j;
                break;
            }
        }
        // cout << "a: " << a << el;
        if (!mismatched && a.length() < b.length())
        {
            string strip = b.substr(a.length());
            // cout << "Strip: " << strip << el;
            ll st = stoll(strip) + 1;
            string st2 = to_string(st);
            if (st2.length() <= strip.length())
            {
                st2 = string(strip.length() - st2.length(), '0') + st2;
                // cout << "st2:" << st2 << el;
                forn(j, st2.length())
                {
                    a.push_back(st2[j]);
                    ans_round++;
                }
            }
        }
        while (stoll(a) <= stoll(b))
        {
            int j = 0;
            forn(k, 10)
            {
                a.push_back(j);
                if (stoll(a) > stoll(b))
                {
                    ans_round++;
                    break;
                }
                a.pop_back();
                j++;
            }
            if (stoll(a) > stoll(b))
            {
                break;
            }
            ans_round++;
            a.push_back('0');
        }
        // cout << tmp << " " << a << " " << ans_round << el;
        ans += ans_round;
        prev = stoll(a);
        // prev = newa;
    }
    cout << ans << el;
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