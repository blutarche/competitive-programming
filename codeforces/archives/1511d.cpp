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

#define mxn 55
int n, k;
int sum[26];
ll g[26][26];
string ans;

void debug()
{
    forn(i, k)
    {
        forn(j, k)
        {
            cout << g[i][j] << " ";
        }
        cout << " : " << sum[i];
        cout << ln;
    }
    cout << "----------------" << ln;
}

void solve()
{
    memset(sum, 0, sizeof(sum));
    memset(g, 0, sizeof(g));
    cin >> n >> k;
    ans.push_back('a');
    char prev = 'a';
    forn(i, n - 1)
    {
        int min = MOD;
        int minsum = MOD;
        char minchar = '0';
        forn(x, k)
        {
            if ((g[prev - 'a'][x] < min) || (g[prev - 'a'][x] == min && minsum >= sum[x]))
            {
                min = g[prev - 'a'][x];
                minsum = sum[x];
                minchar = 'a' + x;
                // cout << "x:" << char('a' + x) << " , minchar:" << minchar << " , min:" << min << " , minsum:" << minsum << ln;
            }
        }
        // cout << "minchar:" << minchar << ln;
        g[prev - 'a'][minchar - 'a']++;
        sum[minchar - 'a'] = g[prev - 'a'][minchar - 'a'];
        forn(i, k)
        {
            if (g[i][minchar - 'a'] < sum[minchar - 'a'])
            {
                sum[minchar - 'a'] = g[i][minchar - 'a'];
            }
        }
        ans.push_back(minchar);
        prev = minchar;
        // debug();
    }
    // debug();
    cout << ans << ln;
}

int main()
{
    fast_cin();
    // int T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    //     cout << "Case #" << i + 1 << ": ";
    //     solve();
    // }
    solve();

    return 0;
}