#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char dir[] = {'D', 'U', 'R', 'L'};

string s;
bool vis[8][8];
int cnt = 0;       //    Number of ways

bool inbounds(int x, int y) {
    return 1 <= x && x <= 7 && 1 <= y && y <= 7;
}

void gen(int x, int y, int i) {
    if (x == 7 && y == 1) {
        if (i == 48) {
            cnt++;
        }
        return;
    }

    // Branch cutting
    // Valid vertical, but invalid horizontal
    if ((!inbounds(x + 1, y) || vis[x + 1][y]) && (!inbounds(x - 1, y) || vis[x - 1][y])) 
        if (inbounds(x, y - 1) && !vis[x][y - 1] && inbounds(x, y + 1) && !vis[x][y + 1]) 
            return;
    
    // Valid horizontal, but invalid vertical
    if ((!inbounds(x, y + 1) || vis[x][y + 1]) && (!inbounds(x, y - 1) || vis[x][y - 1])) 
        if (inbounds(x + 1, y) && !vis[x + 1][y] && inbounds(x - 1, y) && !vis[x - 1][y]) 
            return;

    vis[x][y] = true;

    if (s[i] == '?') {
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (inbounds(nx, ny) && !vis[nx][ny])
            {
                gen(nx, ny, i + 1);
            }
        }
    } else {
        int k = find(dir, dir + 4, s[i]) - dir;
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (inbounds(nx, ny) && !vis[nx][ny])
        {
            gen(nx, ny, i + 1);
        }
    }

    vis[x][y] = false;
}

int main() {
    getline(cin, s);
    memset(vis, false, sizeof(vis));
    gen(1, 1, 0);
    cout << cnt << endl;
    return 0;
}
