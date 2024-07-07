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
    long long ans = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}