// 0/1 Knapsack (value based DP O(n*W)) - typical CP template
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W; if (!(cin >> n >> W)) return 0;
    vector<int> wt(n), val(n);
    for (int i=0;i<n;i++) cin>>wt[i]>>val[i];
    vector<long long> dp(W+1, 0);
    for (int i=0;i<n;i++) {
        for (int w=W; w>=wt[i]; --w)
            dp[w] = max(dp[w], dp[w-wt[i]] + val[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}