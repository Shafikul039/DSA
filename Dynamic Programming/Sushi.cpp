double dp[N][N][N];

double func(ll cnt3, ll cnt2, ll cnt1) {
    if (!cnt3 && !cnt2 && !cnt1) return 0;
    if (dp[cnt3][cnt2][cnt1] != -1) return dp[cnt3][cnt2][cnt1];

    double res = 1.0;
    if (cnt3) res += (cnt3*1.0/n) * func(cnt3-1, cnt2+1, cnt1);
    if (cnt2) res += (cnt2*1.0/n) * func(cnt3, cnt2-1, cnt1+1);
    if (cnt1) res += (cnt1*1.0/n) * func(cnt3, cnt2, cnt1-1);
    
    res = res/ (1.0 - (n-cnt3-cnt2-cnt1)*1.0/n);
    return dp[cnt3][cnt2][cnt1] = res;
}

//dp[cnt3][cnt2][cnt1] = (1 + p3 + p2 + p1) / (1 - p0)
