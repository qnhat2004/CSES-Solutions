#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    int l = 0, r = 0, res = 0;
    set<long long> s;
    while (r < n) {
        while (s.find(a[r]) != s.end()) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        res = max(res, r - l + 1);
        r++;
    }
    cout << res << endl;
    return 0;
}