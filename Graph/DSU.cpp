#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+7;
ll parent[N], Size[N];

void make(ll v) {
    parent[v] = v;
    Size[v] = 1;
}

ll find(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(ll u, ll v) {
    ll p1 = find(u), p2 = find(v);
    if (p1 != p2) {
        if (Size[p1] < Size[p2]) swap(p1, p2);
        parent[p2] = p1;
        Size[p1] += Size[p2];
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) make(i);

        while (k--) {
            ll u, v; cin >> u >> v;
            Union(u, v);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) ans++;
        }

        cout << ans << "\n";
    }
}
