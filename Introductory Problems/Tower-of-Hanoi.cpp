#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<pair<int, int>> steps;

void solve(int n, int a, int b, int c) { // a = from, b = to, c = aux, aux = auxiliary
    if (n == 1) {
        steps.push_back({a, b}); // if there is only one disk, move it from a to b
        cnt++;
        return;
    }
    solve(n - 1, a, c, b); // move n-1 disks from a to c using b as auxiliary
    steps.push_back({a, b}); // move the nth disk from a to b
    cnt++;
    solve(n - 1, c, b, a); // move n-1 disks from c to b using a as auxiliary
}

int main()
{
    int n;
    cin >> n;
    solve(n, 1, 2, 3);
    cout << cnt << endl;
    for (auto i : steps) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}