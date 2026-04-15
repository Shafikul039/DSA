//Finds The Size of The Lis
ll Lis(vector<ll> &arr) {
    vector<ll> lis;
    for (auto &u : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), u);

        if (it == lis.end()) lis.push_back(u);
        else *it = u;
    }
    
    return lis.size();
}

//Finds The Lis Array
vector<ll> LisArray(vector<ll> &arr) {
    ll n = arr.size();
    vector<ll> lis, pos(n);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

        pos[i] = it - lis.begin() + 1;
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }
    
    vector<ll> ans;
    ll curr = lis.size();
    for (int i = n-1; i >= 0; i--) {
        if (pos[i] == curr) {
            ans.push_back(arr[i]);
            curr--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
