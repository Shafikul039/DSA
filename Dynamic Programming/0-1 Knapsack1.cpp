ll fun(ll pos, ll wt){
    if(wt == 0) return 0;
    if(pos < 0) return 0;
    if(dp[pos][wt] != -1) return dp[pos][wt];

    ll ans = fun (pos-1, wt);
    if(wt - a[pos].ff >= 0) {
        ans = max (ans, fun(pos-1, wt - a[pos].ff) + a[pos].ss);
    }

    return dp[pos][wt]=ans;
}
