ll sum_floor_divisions(ll n) {
    ll sum = 0;
    for (ll left = 1, right; left <= n; left = right + 1) {
        ll k = n / left;
        right = n / k;
        ll count = right - left + 1;
        sum += count * k;
    }
    return sum;
}
