ll fun(ll pos){
    if(pos==0)return 0;
    if(dp[pos]!=-1)return dp[pos];
    ll val=fun(pos-1)+abs(a[pos]-a[pos-1]);
    if(pos>1)val=min(val,fun(pos-2)+abs(a[pos]-a[pos-2]));
    return dp[pos]=val;
}
