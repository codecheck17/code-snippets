// Generic integer binary search (first true) template
#include <bits/stdc++.h>
using namespace std;

long long first_true(long long low, long long high, const function<bool(long long)>& f) {
    long long l = low, r = high;
    while (l < r) {
        long long m = l + (r - l) / 2;
        if (f(m)) r = m;
        else l = m + 1;
    }
    return l; // index of first true (ensure f(high) is true)
}