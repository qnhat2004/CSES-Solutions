#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<long long> ms;
    ms.insert(a[0]);
    for (int i = 1; i < n; i++) {
        auto it = ms.upper_bound(a[i]);
        if (it != ms.end()) {
            ms.erase(it);
            ms.insert(a[i]);
        } else {
            ms.insert(a[i]);
        }
    }
    cout << ms.size() << endl;
    return 0;
}