#include <iostream>
#include <string>
using namespace std;
const int N = 1e3;
int dp[N][N];
int lcs(string &s, string &s1, int n, int n1) {
    if (n == 0 || n1 == 0)
        return 0;
    if (dp[n][n1] != -1)
        return dp[n][n1];
    if (s[n - 1] == s1[n1 - 1])
        return dp[n][n1] = 1 + lcs(s, s1, n - 1, n1 - 1);
    else
        return dp[n][n1] = max(lcs(s, s1, n, n1 - 1), lcs(s, s1, n - 1, n1));
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    string s, s1;
    cin >> s >> s1;
    int n = s.size();
    int n1 = s1.size();
    cout << lcs(s, s1, n, n1) << endl;
    return 0;
}
