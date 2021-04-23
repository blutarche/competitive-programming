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

#define mxn 100
int n;
string s1, s2, s3;

string foo(string a, string b)
{
    int ia = 0;
    int ib = 0;
    string ans = "";
    while (ia < 2 * n || ib < 2 * n)
    {
        if (ia < 2 * n && ib < 2 * n && a[ia] == b[ib])
        {
            ans.push_back(a[ia]);
            ia++;
            ib++;
        }
        else if (ia < ib)
        {
            ans.push_back(a[ia]);
            ia++;
        }
        else
        {
            ans.push_back(b[ib]);
            ib++;
        }
    }
    while (ans.length() < 3 * n)
    {
        ans.push_back('0');
    }

    return ans;
}

void solve()
{
    cin >> n;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    string s12 = foo(s1, s2);
    string s23 = foo(s2, s3);
    string s13 = foo(s1, s3);
    if (s12.length() == 3 * n)
    {
        cout << s12 << ln;
    }
    else if (s23.length() == 3 * n)
    {
        cout << s23 << ln;
    }
    else if (s13.length() == 3 * n)
    {
        cout << s13 << ln;
    }
    else
        cout << "======" << ln;
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