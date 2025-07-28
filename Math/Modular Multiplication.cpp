ll binmulty(ll a, ll b) {
    ll ans = 0;
    a %= M;
    while (b) {
        if (b & 1) ans = (ans + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}
