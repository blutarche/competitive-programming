#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define INF 2e18
ll MOD = 998244353;
bool __DEBUG__ = false;

ll year;
ll min_year;
ll min_by_digit[20];

ll find_digit(ll x)
{
    return floor(log10(x) + 1);
}

ll concat_num(ll num, ll cur, ll count)
{
    ll x = num + 1;
    ll digits = find_digit(x);
    cur = cur * (ll)pow(10, digits) + x;
    if (count > 0 && cur > year)
    {
        return cur;
    }
    return concat_num(x, cur, count + 1);
}

void debug() {
    forn(i, 20) {
        cout << min_by_digit[i] << " ";
    }
    cout << el;
}

void solve()
{
    min_year = pow(10,18) + 7;
    forn(i, 20) {
        min_by_digit[i] = pow(10, 18) + 7;
    }
    cin >> year;
    ll dig = find_digit(year);
    ll div = pow(10, dig - 1);
    for (ll i = 0; i < dig / 2; i++, div /= 10) {
        ll start = year / div;
        if (__DEBUG__) cout << "start: " << start << el;
        ll limit = pow(10, i + 1);
        for (ll x = start; x < limit; x++) {
            ll closest = concat_num(x - 1, 0, 0);
            if (__DEBUG__) cout << "x: " << x << " " << "closest: " << closest << el;
            ll closest_dig = find_digit(closest);
            if (closest < min_by_digit[closest_dig]) {
                min_by_digit[closest_dig] = closest;
                if (closest < min_year) {
                    min_year = closest;
                }
            } else {
                break;
            }
        }
        for (ll x = start+1; x < limit; x++) {
            ll closest = concat_num(x - 1, 0, 0);
            if (__DEBUG__) cout << "x: " << x << " " << "closest: " << closest << el;
            ll closest_dig = find_digit(closest);
            if (closest < min_by_digit[closest_dig]) {
                min_by_digit[closest_dig] = closest;
                if (closest < min_year) {
                    min_year = closest;
                }
            } else {
                break;
            }
        }
        // if (__DEBUG__) debug();
    }
    cout << min_year << ln;
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

    return 0;
}