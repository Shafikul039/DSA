ll bigmod(ll a, ll b) {
    ll ans=1;
    a = a % M;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % M;
        }
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}

ll binmulty(ll a, ll b) {
        ll ans=0;
        a = a % M;
        while (b) {
            if (b & 1) {
                ans = (ans + a) % M;
            }
            a = (a + a) % M;
            b >>= 1;
        }
        return ans;
}
