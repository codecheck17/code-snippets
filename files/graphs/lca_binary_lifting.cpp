// LCA with binary lifting (O(log N) queries, O(N log N) preprocess)
#include <bits/stdc++.h>
using namespace std;
int LOG;
vector<vector<int>> up;
vector<int> tin, tout;
int timer = 0;

void dfs(int v, int p, const vector<vector<int>>& g) {
    tin[v] = ++timer;
    up[v][0] = p < 0 ? v : p;
    for (int j = 1; j < LOG; ++j) up[v][j] = up[ up[v][j-1] ][j-1];
    for (int to : g[v]) if (to != p) dfs(to, v, g);
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { // u is ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int j = LOG-1; j >= 0; --j) {
        if (!is_ancestor(up[u][j], v)) u = up[u][j];
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LOG = 1; while ((1<<LOG) <= n) ++LOG;
    up.assign(n, vector<int>(LOG));
    tin.assign(n,0); tout.assign(n,0);
    dfs(0, -1, g);
    int q; cin >> q;
    while (q--) {
        int u,v; cin >> u >> v; --u; --v;
        cout << lca(u,v)+1 << '\n'; // +1 if 1-indexed output desired
    }
}