#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
string s;
bool vis[7][7];
int dp[7][7][49];

bool check(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

int gen(int x, int y, int pos) {
    if (x == 6 && y == 0) {
        if (pos == 48) return 1;
        return 0;
    }

    if (pos == 48) return 0;
    if (dp[x][y][pos] != -1) return dp[x][y][pos];

    vis[x][y] = true;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (s[pos] == '?' || s[pos] == dir[i]) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && !vis[nx][ny]) {
                cnt += gen(nx, ny, pos + 1);
            }
        }
    }
    vis[x][y] = false;
    return dp[x][y][pos] = cnt;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    cout << gen(0, 0, 0) << endl;
    return 0;
}
