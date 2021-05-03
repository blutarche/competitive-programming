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

#define mxn 101
#define mxk 10001
int n, x_input;
vi s;

void solve()
{
    s.clear();
    cin >> n >> x_input;
    int sum = 0;
    forn(i, n) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        s.push_back(tmp);
    }
    if (sum == x_input) {
        cout << "NO" << ln;
        return;
    }
    if (sum < x_input) {
        cout << "YES" << ln;
        for (int x : s) {
            cout << x << " ";
        }
        cout << ln;
        return;
    }
    sort(s.rbegin(), s.rend());
    int tmpsum = 0;
    vi ans;
    forn (i, n) {
        int num = -1;
        int j =0;
        for (int xx : s) {
            if (tmpsum + xx != x_input) {
                num = xx;
                break;
            }
            j++;
        }
        // cout << num << " ";
        if (num == -1) {
            cout << "NO" << ln;
            return;
        }
        tmpsum += num;
        ans.push_back(num);
        s.erase(s.begin() + j);
    }

    cout << "YES" << ln;
    for (int x : ans) {
        cout << x << " ";
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