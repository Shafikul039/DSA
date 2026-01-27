const ll N = 4e5 + 7, Log = 20;
vector<ll> adj[N];
ll up[N][Log], depth[N];

void dfs(ll ver, ll parent = -1) {
    for (auto &child : adj[ver]) {
        if (child == parent) continue;

        depth[child]  = depth[ver] + 1;
        up[child][0] = ver;
        for (int j = 1; j < Log; j++) {
            up[child][j] = up[ up[child][j-1] ][j-1];
        }

        dfs(child, ver);
    }
}

ll kth_ancestor(ll a, ll k) {
    for (int j = 0; j < Log; j++) {
        if (k & (1 << j)) a = up[a][j];
    }

    return a;
}

ll get_lca(ll a, ll b) {
    if (depth[a] < depth[b]) swap(a, b);

    a = kth_ancestor(a, depth[a] - depth[b]);
    if (a == b) return a;

    for (int j = Log-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}
