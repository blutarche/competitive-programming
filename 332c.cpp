#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];
pair<pair<int, int>, int> P[100005];
int main() {
    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    for(int i=1;i<=n;i++){
        scanf("%d%d", &a[i], &b[i]);
        P[i] = make_pair(make_pair(b[i], -a[i]), i);
    }
    sort(P+1, P+1+n);
    vector<pair<pair<int, int>, int> > v;
    for(int i=n;i>=p-k+1;i--){
        v.push_back(make_pair(make_pair(P[i].first.second, -P[i].first.first), P[i].second));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<p;i++) printf("%d ", v[i].second);
    printf("\n");
}