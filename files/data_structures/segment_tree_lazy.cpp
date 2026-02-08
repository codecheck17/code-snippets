// Segment tree with range add and range sum (lazy propagation)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> st, lazy;
    SegTree(int _n): n(_n) {
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] += lazy[p] * (r-l+1);
            if (l != r) {
                lazy[p<<1] += lazy[p];
                lazy[p<<1|1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
    void update(int p, int l, int r, int i, int j, ll val) {
        push(p,l,r);
        if (i>r || j<l) return;
        if (i<=l && r<=j) {
            lazy[p] += val; push(p,l,r); return;
        }
        int m=(l+r)>>1;
        update(p<<1,l,m,i,j,val); update(p<<1|1,m+1,r,i,j,val);
        st[p] = st[p<<1] + st[p<<1|1];
    }
    ll query(int p, int l, int r, int i, int j) {
        if (i>r || j<l) return 0;
        push(p,l,r);
        if (i<=l && r<=j) return st[p];
        int m=(l+r)>>1;
        return query(p<<1,l,m,i,j) + query(p<<1|1,m+1,r,i,j);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    SegTree st(n);
    while (q--) {
        int type; cin >> type;
        if (type==1) {
            int l,r; long long v; cin>>l>>r>>v; st.update(1,1,n,l,r,v);
        } else {
            int l,r; cin>>l>>r; cout << st.query(1,1,n,l,r) << '\n';
        }
    }
}