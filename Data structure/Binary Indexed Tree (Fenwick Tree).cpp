#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll bit[N], n, arr[N];

void update(ll i, ll x) {
    for ( ; i <= n; i += i & (-i)) bit[i] += x;
}

ll sum(ll i) {
    ll ans = 0;
    for ( ; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        ll k; cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            update(i, arr[i]);
        }

        while (k--) {
            ll type; cin >> type;
            if (type == 1) {
                ll ind, x; cin >> ind >> x;
                update(ind, x - arr[ind]);
                arr[ind] = x;
            }
            else {
                ll l, r; cin >> l >> r;
                cout << sum(r) - sum(l - 1) << "\n";
            }
        }
    }
}
