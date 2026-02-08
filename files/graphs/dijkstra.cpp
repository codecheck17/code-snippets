// Dijkstra - shortest paths with priority queue
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

vector<ll> dijkstra(int s, const vector<vector<pair<int,int>>>& g) {
    int n = g.size();
    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto [to, w] : g[v]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        g[u].push_back({v,w});
        g[v].push_back({u,w}); // remove for directed
    }
    auto dist = dijkstra(0, g);
    for (auto x : dist) cout << (x==INF ? -1 : x) << ' ';
    cout << '\n';
}