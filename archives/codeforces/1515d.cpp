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
bool __DEBUG__ = false;

#define mxn 200001
int n, l, r;
vi c;
int diff[mxn];
int ans;

void debug() {
    if (!__DEBUG__) return;
    forn(i, n) {
        cout << diff[i + 1] << " ";
    }
    cout << " : " << ans << " r:" << r << " l:" << l;
    cout << ln;
}

void solve()
{
    memset(diff, 0, sizeof(diff));
    ans = 0;
    cin >> n >> l >> r;
    forn(i, n) {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
        if (i < l) {
            diff[tmp]++;
        } else {
            diff[tmp]--;
        }
    }
    // convert same colors
    forn (i, n) {
        int color = i + 1;
        if (diff[color] == 0) continue;
        if (diff[color] < 0 && r < l) continue;
        if (diff[color] > 0 && l < r) continue;
        if (diff[color] < 0) {
            while (diff[color] < -1 && r > l) {
                diff[color] += 2;
                ans++;
                r--;
                l++;
            }
        } else if (diff[color] > 0) {
            while (diff[color] > 1 && l > r) {
                diff[color] -= 2;
                ans++;
                r++;
                l--;
            }
        }
    }
    debug();
    ans += abs (n / 2 - l);
    l = n/2;
    r = n/2;
    int sum = 0;
    forn(i, n) {
        sum += abs(diff[i + 1]);
    }
    ans += sum / 2;
    debug();
    cout << ans << ln;
    if (__DEBUG__) cout << "-----" << ln;
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