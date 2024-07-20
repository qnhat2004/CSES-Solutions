#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long total = n * (n + 1) / 2;
    if (total & 1) {
        cout << "NO\n";
        return 0;
    } 
    vector<int> set1, set2;
    long long sum1 = 0, sum2 = 0;
    for (int i = n; i >= 1; i--) {
        if (sum1 <= sum2) {
            set1.push_back(i);
            sum1 += i;
        } else {
            set2.push_back(i);
            sum2 += i;
        }
    }
    if (sum1 != sum2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << set1.size() << endl;
        for (auto &i : set1) cout << i << " "; cout << endl;
        cout << set2.size() << endl;
        for (auto &i : set2) cout << i << " ";
    }
    return 0;
}