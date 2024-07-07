#include <bits/stdc++.h>
using namespace std;

long long count(long long a[], int n, long long cur) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(cur - a[i]);
    }
    return ans;
}

int main()
{
    int n; 
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << count(a, n, a[n / 2]) << endl;
    return 0;
}