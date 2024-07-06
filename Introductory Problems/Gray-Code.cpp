#include <bits/stdc++.h>
using namespace std;

int n;

void gen(string s, int i)
{
    if (i == n)
    {
        cout << s << endl;
        return;
    }
    gen(s + "0", i + 1);
    gen(s + "1", i + 1);
}

int main()
{
    cin >> n;
    gen("", 0);
    return 0;
}