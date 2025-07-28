const int N = 1e6 + 7;
int spf[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}


map<int, int> get_factors(int x) {
    map<int, int> res;
    while (x > 1) {
        res[spf[x]]++;
        x /= spf[x];
    }
    return res;
}
