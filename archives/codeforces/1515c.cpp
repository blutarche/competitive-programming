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

#define INF 2e18
ll MOD = 998244353;

#define mxn 1e5
int n, m, x;
int tower[100001];
vpi h;
multiset<pi> pq;

void solve()
{
    memset(tower, 0, sizeof(tower));
    h.clear();
    pq.clear();
    cin >> n >> m >> x;
    forn (i, n) {
        int tmp;
        cin >> tmp;
        h.push_back(mp(tmp, i));
    }
    sort(h.rbegin(), h.rend());
    forn(i, m) {
        pq.insert(mp(0, i + 1));
    }
    for (pi p : h) {
        int height = p.fi;
        int idx = p.se;

        pi shortest = *pq.begin();
        pq.erase(pq.begin());
        pq.insert(mp(shortest.fi + height, shortest.se));

        tower[idx] = shortest.se;
    }

    pi shortest = *pq.begin();
    pi tallest = *(prev(pq.end()));
    if (tallest.fi - shortest.fi > x) {
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    // for (pi p : pq) {
    //     cout << p.fi << " " << p.se << ln;
    // }
    forn(i, n) {
        cout << tower[i] << " ";
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