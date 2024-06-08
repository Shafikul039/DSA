ll bigmod(ll a,ll b,ll m){
    if(b==0)return 1;
    if(b%2!=0)return ((a%m) * bigmod(a,b-1,m))%m;
    else{
        return ((bigmod(a,b/2,m)%m) * (bigmod(a,b/2,m)%m))%m;
    }
}
