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
ll MOD = 1000000007;
#define fast_cin()                                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                                        \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define mxn 300005
ll seg = 1000;
int n, q;
vi v;
vector<map<int, int>> vm;

struct comp
{
    template <typename T>

    // Comparator function
    bool operator()(const T &l,
                                    const T &r) const
    {
        if (l.second != r.second)
        {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

void ask()
{
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int len = r - l + 1;
    int segl = l / seg;
    int segr = r / seg;
    // cout << "segl:" << segl << " segr:" << segr << ln;
    set<pi, comp> s;
    map<int, int> m;
    if (segl != segr)
    {
        for (int i = l; i < n && i < (segl + 1) * seg && r; i++)
        {
            m[v[i]]++;
        }
        for (int i = (segr + 1) * seg; i < n && i <= r; i++)
        {
            m[v[i]]++;
        }
        for (int segg = segl + 1; segg < segr; segg++)
        {
            map<int, int> mv = vm[segg];
            for (auto mm : mv)
            {
                m[mm.fi] += mm.se;
            }
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
            m[v[i]]++;
    }
    int max = -1;
    for (auto mp : m)
    {
        // cout << mp.fi << " " << mp.se << ln;
        if (mp.se > max)
            max = mp.se;
    }
    int ans = 1;

    while (max > ceil(1.0 * len / 2.0) && max > 0)
    {
        if (len > max)
        {
            int wanna_remove = ceil(max / 2.0);
            int left = min(len - max, wanna_remove - 1);
            int tmpmax = min(wanna_remove, left + 1);
            max -= tmpmax;
            len -= left;
            ans++;
        }
        else
        {
            ans += max - 1;
            break;
        }
    }
    cout << ans << ln;
}

void solve()
{
    cin >> n >> q;
    forn(i, n)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if (i % seg == 0)
        {
            vm.push_back(map<int, int>());
        }
        int idx = i / seg;
        vm[idx][tmp]++;
    }
    // forn(i, vm.size())
    // {
    //     cout << i * seg << ":" << ln;
    //     for (auto m : vm[i])
    //     {
    //         cout << m.fi << " " << m.se << ln;
    //     }
    //     cout << "---" << ln;
    // }
    forn(i, q)
    {
        ask();
    }
}

int main()
{
    fast_cin();
    // int T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    //     // cout << "Case #" << i + 1 << ": ";
    //     solve();
    // }
    solve();

    return 0;
}