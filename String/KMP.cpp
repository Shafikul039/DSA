#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 7;
ll pref[N];

void prefix_functio(string s) {
    ll n = s.size();
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[j] != s[i]) j = pref[j-1];

        if (s[j] == s[i]) j++;
        pref[i] = j;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        string s, tmp; cin >> s >> tmp;

        s = tmp + '#' + s;
        prefix_functio(s);

        ll n = tmp.size();
        vector<ll> ans;
        for (int i = n+1; i < s.size(); i++) {
            if (pref[i] == n) ans.push_back(i-2*n+1);
        }

        cout << ans.size() << "\n";
        for (auto &u : ans) cout << u << " "; cout << "\n";
    }
}
