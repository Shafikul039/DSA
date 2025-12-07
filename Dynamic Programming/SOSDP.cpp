ll forward1(ll dp[]) { //add elements to its supersets
    for (ll bit = 0; bit < Mlog; bit++) {
        for (ll i = 0; i < N; i++) {
            if (i & (1<<bit)) dp[i] += dp[i ^ (1<<bit)];
        }
    }
}

ll backward1(ll dp[]) {
    for (ll bit = 0; bit < Mlog; bit++) {
        for (ll i = N - 1; i >= 0; i--) {
            if (i & (1<<bit)) dp[i] -= dp[i ^ (1<<bit)];
        }
    }
}

ll forward2(ll dp[]) { // add elements to its subsets
    for (ll bit = 0; bit < Mlog; bit++) {
        for (ll i = N - 1; i >= 0; i--) {
            if (i & (1<<bit)) dp[i ^ (1<<bit)] += dp[i];
        }
    }
}

ll backward2(ll dp[]) {
    for (ll bit = 0; bit < Mlog; bit++) {
        for (ll i = 0; i < N; i++) {
            if (i & (1<<bit)) dp[i ^ (1<<bit)] -= dp[i];
        }
    }
}
