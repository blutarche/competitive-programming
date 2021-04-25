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
int n, a, b;
map<int, int> m, m_process;
int sum = 0;

void try_split(int x) {
    if (x < 0) return;
    if (m_process[x] > 0) {
        m_process[x]--;
        sum--;
        return;
    }
    if (sum <= 0) return;
    try_split(x - a);
    try_split(x - b);
}

void solve()
{
    m.clear();
    cin >> n >> a >> b;

    int tmp_sum = 0;
    forn (i, n) {
        int tmp;
        cin >> tmp;
        m[i+1]+= tmp;
        tmp_sum += tmp;
    }
    // for (auto p : m) {
    //     cout << p.fi << " " << p.se << ln;
    // }
    int ans = 0;
    int i = n;
    for (i = n; i < 20*20*20; i++) {
        sum = tmp_sum;
        m_process = m;
        // cout << "i:" << i << ln;
        try_split(i);
        // cout << i << " : " << sum << ln;
        if (sum <= 0) {
            ans = i;
            break;
        }
    }
    cout << ans << ln;
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