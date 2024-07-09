#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        a[i] = (i != n ? (i + 1) : 1); // Linked list
    }
    int cur = 1;
    while (cur != a[cur]) {
        cout << a[cur] << " ";  // Print the next element
        a[cur] = a[a[cur]];  // Skip the next element
        cur = a[cur]; // Move to the next element
    }
    cout << cur;
    return 0;
}