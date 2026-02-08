// Dinic's algorithm - fast max flow (adj list with edge struct)
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to; long long cap; int rev; };
struct Dinic {
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;
    Dinic(int n): n(n), g(n), level(n), it(n) {}
    void add_edge(int u, int v, long long c) {
        g[u].push_back({v,c,(int)g[v].size()});
        g[v].push_back({u,0,(int)g[u].size()-1});
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q; level[s]=0; q.push(s);
        while (!q.empty()) {
            int v=q.front(); q.pop();
            for (auto &e : g[v]) if (e.cap>0 && level[e.to]==-1) {
                level[e.to]=level[v]+1; q.push(e.to);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int v, int t, long long f) {
        if (!f) return 0;
        if (v==t) return f;
        for (int &i = it[v]; i < (int)g[v].size(); ++i) {
            Edge &e = g[v][i];
            if (e.cap > 0 && level[e.to] == level[v] + 1) {
                long long got = dfs(e.to, t, min(f, e.cap));
                if (got) {
                    e.cap -= got; g[e.to][e.rev].cap += got;
                    return got;
                }
            }
        }
        return 0;
    }
    long long maxflow(int s, int t) {
        long long flow = 0;
        while (bfs(s,t)) {
            fill(it.begin(), it.end(), 0);
            while (long long pushed = dfs(s,t,LLONG_MAX)) flow += pushed;
        }
        return flow;
    }
};