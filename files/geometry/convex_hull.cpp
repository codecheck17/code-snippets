// Monotonic chain convex hull (returns points on hull in CCW order)
// Points are pair<long long,long long>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Point = pair<ll,ll>;

ll cross(const Point& O, const Point& A, const Point& B) {
    return (A.first - O.first) * (B.second - O.second)
         - (A.second - O.second) * (B.first - O.first);
}

vector<Point> convex_hull(vector<Point>& pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 1) return pts;
    vector<Point> lower, upper;
    for (auto &p : pts) {
        while (lower.size() >= 2 && cross(lower[lower.size()-2], lower.back(), p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }
    for (int i = (int)pts.size()-1; i >= 0; --i) {
        auto &p = pts[i];
        while (upper.size() >= 2 && cross(upper[upper.size()-2], upper.back(), p) <= 0)
            upper.pop_back();
        upper.push_back(p);
    }
    lower.pop_back(); upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}