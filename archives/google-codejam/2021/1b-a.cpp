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
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define INF 1e9
ll pow10e9 = 1000000000;
ll MOD = 360l * 12l * pow10e9 * 10;

#define mxn 505
ll a, b, c;

ll second_div = pow10e9;
ll minute_div = 60 * second_div;
ll hour_div = 60 * minute_div;

ll hour, minute, sec, ns;

bool find_ns(ll h, ll m, ll s) {
    if (m % 12 != 0) return false;
    if (s % 720 != 0) return false;
    ll tmp_hour = h / hour_div;
    ll hour_min = (h % hour_div) / minute_div;
    ll hour_sec = (h % minute_div) / second_div;
    ll hour_ns = h % second_div;

    ll minute_ns = m / 12;
    ll tmp_minute = minute_ns / minute_div;
    ll min_sec = (minute_ns % minute_div) / second_div;
    ll min_ns = minute_ns % second_div;

    ll second_ns = s / 720;
    ll tmp_sec = second_ns / second_div;

    ll tmp_ns = second_ns % second_div;
    if (tmp_minute != hour_min) return false;
    if (tmp_sec != min_sec || tmp_sec != hour_sec) return false;
    if (tmp_ns != hour_ns || tmp_ns != min_ns) return false;
    // cout << "hour: " << h << " = " << hour << ":" << hour_min << ":" << hour_sec << "." << hour_ns << ln;
    // cout << "min: " << m << " = " << minute << ":" << min_sec << "." << min_ns << ln;
    // cout << "sec: " << s << " = " << sec << "." << ns << ln;
    hour = tmp_hour;
    minute = tmp_minute;
    sec = tmp_sec;
    ns = tmp_ns;
    return true;
}

void print_ans() {
    cout << hour << " " << minute << " " << sec << " " << ns << ln;
}

void solve()
{
    cin >> a >> b >> c;
    ll adder = 100000000;
    for (ll i = 0; i <= MOD; i += adder) {
        // cout << i << ln;
        a %= MOD;
        b %= MOD;
        c %= MOD;
        if (find_ns(a, b, c)) break;
        if (find_ns(a, c, b)) break;
        if (find_ns(b, a, c)) break;
        if (find_ns(b, c, a)) break;
        if (find_ns(c, b, a)) break;
        if (find_ns(c, a, b)) break;
        a += adder;
        b += adder;
        c += adder;
    }
    // cout << a << " " << b << " " << c << ln;
    print_ans();
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