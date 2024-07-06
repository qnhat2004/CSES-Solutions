#include <bits/stdc++.h>
using namespace std;
// solved time: 35p
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) // 
    {
        long long total = (long long)k * k; // total number of squares
        long long ans = total * (total - 1) / 2; // total number of ways to put 2 knights
        if (k > 2)
        {
            ans -= 4 * (k - 1) * (k - 2);
        }
        cout << ans << endl;
    }

    return 0;
}