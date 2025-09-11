vector<ll> findDiv(const vector<pair<ll,ll>> &freq) {
    vector<ll> divisors, temp;
            divisors.push_back(1);
            for (auto &u : freq) {
                temp.clear();
                ll now = 1;
                for (ll k = 0; k <= u.second; k++, now *= u.first) {
                    for (auto &v : divisors) temp.push_back(v*now);
                }
                divisors = temp;
            }
 
    return divisors;
}
