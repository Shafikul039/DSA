const int N = 2e5 + 7;
ll bit[N], arr[N];

// increment x in arr[i]
void update(ll i, ll x, ll n) {
    for ( ; i <= n; i += i & (-i)) bit[i] += x;
}

ll sum(ll i) {
    ll ans = 0;
    for ( ; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

ll query(ll l, ll r) {
    return sum(r) - sum(l - 1);
}
