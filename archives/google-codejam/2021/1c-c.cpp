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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define INF 1e9
ll MOD = 998244353;

#define MAX 10000000
#define MAX_OP 16
string s, e;
queue<string> q;
int min_op;

string nott(string a) {
    string ans = "";
    bool break_leading = false;
    forn (i, a.length()) {
        if (a[i] == '0') {
            break_leading = true;
            ans = ans + '1';
        } else if (break_leading) {
            ans = ans + '0';
        }
    }
    if (ans.length() == 0) return "0";
    return ans;
}

string doubl(string a) {
    if (a == "0") return "0";
    return a + "0";
}

void brute(string a, string b, int number_of_op) {
    if (number_of_op > min_op) return;
    if (number_of_op > MAX_OP) return;
    // cout << "test: " << a << " " << b << " " << number_of_op << ln;
    if (a == b) {
        min_op = number_of_op;
        return;
    }
    brute(nott(a), number_of_op + 1);
    brute(doubl(a), number_of_op + 1);
}

void solve()
{
    min_op = INF;
    cin >> s >> e;
    q.insert(s);
    brute(s, 0);
    if (min_op == INF) {
        cout << "IMPOSSIBLE" << ln;
    } else {
        cout << min_op << ln;
    }
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