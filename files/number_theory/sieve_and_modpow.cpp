// Sieve of Eratosthenes + modular exponentiation and modular inverse (mod prime)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<char> is_composite(n+1, false);
    for (int i = 2; i <= n; ++i) {
        if (!is_composite[i]) primes.push_back(i);
        for (int p : primes) {
            if ((long long)i * p > n) break;
            is_composite[i*p] = true;
            if (i % p == 0) break;
        }
    }
    return primes;
}

ll mod_pow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e) {
        if (e&1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

ll mod_inv(ll a, ll mod) { return mod_pow(a, mod-2, mod); } // mod prime

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    auto primes = sieve(n);
    for (int p : primes) cout << p << ' ';
    cout << '\n';
}