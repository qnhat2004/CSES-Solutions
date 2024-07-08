#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int cnt = 1, cur = a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].second < cur) {
            cnt++;
        }
        cur = a[i].second;
    }
    cout << cnt << endl;
    return 0;
}