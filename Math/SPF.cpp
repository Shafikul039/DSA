const int N = 1e6 + 2;
int spf[N];

void sieve() {
    for (int i = 2; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i += 2) spf[i] = 2;
    for (int i = 3; i*i < N; i += 2) {
        if (spf[i] == i) {
            for (int j = i*i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
