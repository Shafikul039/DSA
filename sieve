void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int>lp(n,0),hp(n,0);

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        lp[p]=hp[p]=p;
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                hp[i]=p;
                isPrime[i] = false;
                if(lp[i]==0){
                    lp[i]=p;
                }
            }
        }
    }
    int a;cin>>a;
    vector<int>prime_factors;
    while(a>1){
        int prime_factor=hp[a];
        while(a%prime_factor==0){
            a/=prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }

    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}
