void compute(ll n, string &s) {
    ll l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) Z[i] = min (r - i, Z[i - l]);

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] > r) {
            l = i;
            r = i + Z[i];
        }
    }
}

//O(n)
