// BFS and DFS (adjacency list)
// C++17 - concise templates for unweighted graphs
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<int>& vis) {
    vis[v] = 1;
    // process v
    for (int to : g[v]) if (!vis[to]) dfs(to, g, vis);
}

vector<int> bfs(int s, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // example: build graph then run
    int n, m; // nodes, edges
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; // 0-indexed or 1-indexed depending on input
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n, 0);
    dfs(0, g, vis);
    auto d = bfs(0, g);
    for (int x : d) cout << x << ' ';
    cout << '\n';
    return 0;
}