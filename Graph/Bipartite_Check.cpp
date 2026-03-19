#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+7;
vector<ll> adj[N];

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        ll n, m; 
        cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            ll a, b; 
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<ll> col(n+1, -1);
        bool is_bipartite = true;

        for (int i = 1; i <= n; i++) {
            if (col[i] != -1) continue;

            queue<ll> q;
            q.push(i);
            col[i] = 0;

            while (!q.empty()) {
                ll ver = q.front(); 
                q.pop();

                for (auto &child : adj[ver]) {
                    if (col[child] == -1) {
                        col[child] = col[ver] ^ 1;
                        q.push(child);
                    }
                    else {
                        if (col[child] == col[ver]) {
                            is_bipartite = false;
                        }
                    }
                }
            }
        }

        cout << (is_bipartite ? "YES\n" : "NO\n");

        for (int i = 1; i <= n; i++) adj[i].clear();
    }
}
