ll fun(ll pos, ll val){
    if(val == 0) return 0;
    if(pos < 0) return 1e17;
    if(dp[pos][val] != -1) return dp[pos][val];

    ll ans = fun (pos-1, val);
    if(val - a[pos].ss >= 0) {
        ans = min (ans, fun(pos-1, val - a[pos].ss) + a[pos].ff);
    }

    return dp[pos][val]=ans;
}
