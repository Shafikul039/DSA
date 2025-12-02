#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 7;
ll dp[N];
vector<ll> a;

ll func(ll n, ll k) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    ll tmp = 1e18;
    for (ll i = n - 1; i >= n - k && i >= 0; i--) {
        tmp = min (tmp, func(i, k) + abs(a[n] - a[i]));
    }
    return dp[n] = tmp;
}

int main() {
    ll n, k; cin >> n >> k;
    a.resize(n);
    for (auto &u: a) cin >> u;
    memset(dp, -1, sizeof(dp));
    ll ans = func(n - 1,k);
    cout << dp[n - 1] << endl;
}
