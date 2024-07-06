#include <bits/stdc++.h>
using namespace std;

int n, total, check = 0, ca = 0;
vector<int> a;
vector<vector<int>> dp;

void gen(int i, int sum) {
    if (sum == total / 2) {
        cout << ca << endl;
        for (int j = 1; j <= n; j++) if (a[j] == 1) cout << j << " "; cout << endl;
        cout << n - ca << endl; 
        for (int j = 1; j <= n; j++) if (a[j] == 0) cout << j << " "; cout << endl;
        check = 1;
        return;
    }
    if (i > n || sum > total / 2 || check || dp[i][sum])
        return;
    dp[i][sum] = 1;
    a[i] = 1;
    ca++;
    gen(i + 1, sum + i);
    a[i] = 0;
    ca--;
    gen(i + 1, sum);
}

int main()
{
    cin >> n;
    total = n * (n + 1) / 2;
    a.resize(n + 5);
    dp.resize(n + 1, vector<int>(total));
    if (total & 1) cout << "NO" << endl;
    else {
        cout << "YES\n";
        gen(1, 0);
    }
    return 0;
}