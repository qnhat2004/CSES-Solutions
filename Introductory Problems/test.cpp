#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char dir[] = { 'R', 'L', 'D', 'U' };
string s;
bool vis[7][7]; // visited
int ans = 0;
int dp[10][10][50];

bool check(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

void gen(int x, int y, int pos) {
    if (x == 6 && y == 0) {
        if (pos == 48) {
            ans++;
        }
        return;
    }
    if (pos == 48) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        if (s[pos] == '?' || s[pos] == dir[i]) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && !vis[nx][ny]) {
                gen(nx, ny, pos + 1);
            }
        }
    }
    vis[x][y] = false;
}

int main() {
    cin >> s;
    gen(0, 0, 0);
    cout << ans << endl;
    return 0;
}
