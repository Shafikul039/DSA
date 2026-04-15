ll Lis(vector<ll> &arr) {
    vector<ll> lis;
    for (auto &u : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), u);

        if (it == lis.end()) lis.push_back(u);
        else *it = u;
    }
    
    return lis.size();
}
