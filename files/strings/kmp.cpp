// KMP prefix-function and pattern occurrences (0-indexed)
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const string& text, const string& pat) {
    string s = pat + '#' + text;
    auto pi = prefix_function(s);
    vector<int> occ;
    for (int i = (int)pat.size()+1; i < (int)s.size(); ++i)
        if (pi[i] == (int)pat.size())
            occ.push_back(i - 2*pat.size()); // 0-indexed position in text
    return occ;
}

int main() {
    string t, p;
    if (!(cin >> t >> p)) return 0;
    auto occ = kmp_search(t,p);
    for (int x : occ) cout << x << ' ';
    cout << '\n';
}