#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

int main()
{
    int n;
    cin >> n;
    vector<pll> a(n);
    for (auto &i : a) {
        cin >> i.first >> i.second;
    }
    sort(a.begin(), a.end(), [](pll x, pll y) {
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= last) {
            ans++;
            last = a[i].second;
        }
    }   
    cout << ans << "\n";
    return 0;
}