// Fenwick Tree (Binary Indexed Tree) for point-update, prefix-sum
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void add(int idx, long long val) { // 1-indexed
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    long long sum(int idx) {
        long long r = 0;
        for (; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    long long range_sum(int l, int r) { return sum(r) - sum(l-1); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; if (!(cin>>n>>q)) return 0;
    Fenwick fw(n);
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int i; long long v; cin >> i >> v; fw.add(i, v);
        } else {
            int l,r; cin>>l>>r; cout << fw.range_sum(l,r) << '\n';
        }
    }
}