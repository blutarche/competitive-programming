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
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxn 1005
int n, q;
map<pl, pl> m;
// <n1,n2> - <load,toll>
map<ll, vl> paths;
map<ll, ll> walk;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

ll find_ans(ll c, ll w)
{
    vl v;
    while (c != 1)
    {
        pl p = mp(c, walk[c]);
        pl val = m[p];
        // cout << p.fi << "," << p.se << " -- " << val.fi << " " << val.se << ln;
        if (w >= val.fi)
        {
            v.push_back(val.se);
        }
        c = walk[c];
    }
    if (v.size() == 0)
    {
        return 0;
    }
    ll cur_gcd = v[0];
    for (ll x : v)
    {
        cur_gcd = gcd(x, cur_gcd);
        // cout << x << " " << cur_gcd << ln;
    }
    // cout << ln;
    return cur_gcd;
}

void gen_path(ll c)
{
    for (ll node : paths[c])
    {
        if (walk.find(node) == walk.end())
        {
            walk[node] = c;
            gen_path(node);
        }
    }
}

void solve()
{
    m.clear();
    paths.clear();
    walk.clear();
    cin >> n >> q;
    forn(i, n - 1)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        m[mp(a, b)] = mp(c, d);
        m[mp(b, a)] = mp(c, d);
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    walk[1] = 0;
    gen_path(1);
    // forn(i, n)
    // {
    //     cout << i << " : " << walk[i] << ln;
    // }
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     pl path = it->fi;
    //     pl val = it->se;
    //     cout << path.fi << "," << path.se << " -- " << val.fi << " " << val.se << ln;
    // }
    forn(i, q)
    {
        ll c, w;
        cin >> c >> w;
        ll ans = find_ans(c, w);
        cout << ans << " ";
        // cout << "-------------" << ln;
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
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    // solve();

    return 0;
}