ll floor_divisions(ll n) {
    ll sum = 0;
    for (ll left = 1, right; left <= n; left = right + 1) {
        ll k = n / left;
        right = n / k;
        ll count = right - left + 1;
        sum += count * k;
    }
    return sum;
}
// n/1 + n/2 + n/3 +....n/n 
//O(sqrt(n))

ll sum_floor_division(ll n) {
    ll total = 0;
    for (ll left = 1, right; left <= n; left = right + 1) {
        ll k = n / left;
        right = n / k;
        ll count = (right - left + 1);
        ll sum_i = (right + left) * count/2;
        total = total + (sum_i * k);
    }

    return total;
}
// (n/1)*1 + (n/2)*2 + (n/3)*3 + .... (n/n)*n;
