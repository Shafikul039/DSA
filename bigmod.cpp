long long bigmod(long long a, long long b) {
    long long ans=1;
    a=a%m;
    while (b) {
        if (b&1) {
            ans=(ans*a)%m;
        }
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
}

long long binmulty(long long a,long long b){
        long long ans=0;
        a=a%m;
        while(b){
            if(b&1){
                ans=(ans+a)%m;
            }
            a=(a+a)%m;
            b>>=1;
        }
        return ans;
}
