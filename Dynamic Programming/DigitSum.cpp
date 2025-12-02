#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 7, M = 1e9 + 7;
ll D, dp[N][2][103];
string nums;

ll func(ll indx, bool tight, ll sum) {
    if (indx == nums.size()) return sum == 0;
    if (dp[indx][tight][sum] != -1) return dp[indx][tight][sum];

    ll limit = (tight ? nums[indx] - '0' : 9), res = 0;
    for (int i = 0; i <= limit; i++) {
        bool newt = tight && (i == limit);
        res = (res + func(indx + 1, newt, (sum + i)%D)) % M;
    }

    return dp[indx][tight][sum] = res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    //cin >> t;
    memset(dp, -1, sizeof(dp));
 
    while (t--) {
        cin >> nums >> D;

        cout << (func(0, 1, 0) - 1 + M) % M << "\n";

    }

}
