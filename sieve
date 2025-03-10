void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int>lp(n,0),hp(n,0);

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p < n; p++) {
        
        if (isPrime[p]) {
            lp[p]=hp[p]=p;
            for (int i = 2*p; i < n; i += p) {
                hp[i]=p;
                isPrime[i] = false;
                if(lp[i]==0){
                    lp[i]=p;
                }
            }
        }
    }
}
