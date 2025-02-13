int lcs(string &s, string &s1, int n, int n1) {
    if (n == 0 || n1 == 0)
        return 0;
    if (dp[n][n1] != -1)
        return dp[n][n1];
    if (s[n - 1] == s1[n1 - 1])
        {return dp[n][n1] = 1 + lcs(s, s1, n - 1, n1 - 1);}
    else
        return dp[n][n1] = max(lcs(s, s1, n, n1 - 1), lcs(s, s1, n - 1, n1));
}

string getLCS(string &s, string &s1, int n, int n1) {
    string lcs_str = "";
    
    while (n > 0 && n1 > 0) {
        if (s[n - 1] == s1[n1 - 1]) {
            lcs_str = s[n - 1] + lcs_str;
            n--; n1--;
        }
        else {
            if (dp[n - 1][n1] >= dp[n][n1 - 1])
                n--;
            else
                n1--;
        }
    }
    return lcs_str;
}
