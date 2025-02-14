int fun(int len, vector<int> &price){
        if (len==0) {
            return 0;
        }
        if(dp[len] != -1)return dp[len];
        
        int ans=0;
        for (int i = 1; i <= price.size(); i++) {
            if(len - i >= 0) {
                ans = max (ans, fun (len - i, price) + price[i-1]);
            }
        }
        return dp[len] = ans;
    }
