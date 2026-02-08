// Disjoint Set Union (union by size & path compression)
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; if (!(cin >> n >> m)) return 0;
    DSU dsu(n);
    while (m--) {
        int t,a,b; cin >> t >> a >> b;
        if (t==1) dsu.unite(a,b);
        else cout << (dsu.find(a)==dsu.find(b)) << '\n';
    }
}