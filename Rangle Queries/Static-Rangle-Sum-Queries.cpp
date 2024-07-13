#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    long long a[n], prefix[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i] = a[i] + (i == 0 ? 0 : prefix[i - 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r - 1] - (l == 1 ? 0 : prefix[l - 2]) << "\n";
    }   
    return 0;
}