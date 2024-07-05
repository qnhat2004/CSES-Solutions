#include <bits/stdc++.h>
using namespace std;

long long n, total = 0, minDiff = INT_MAX, a[30];

void gen(int i, long long sum) {
    if (i >= n) {
        minDiff = min(minDiff, abs(total - 2 * sum));
        return;
    }
    gen(i + 1, sum);
    gen(i + 1, sum + a[i]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], total += a[i];
    gen(0, 0ll);
    cout << minDiff << endl;
    return 0;
}