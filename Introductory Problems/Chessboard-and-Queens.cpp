#include <bits/stdc++.h>
using namespace std;

int cnt = 0, ans = 0, a[10];
vector<string> matrix(10, string(10, '.'));

bool survive(int row, int col) { // current row, current col
	for (int i = 0; i < row; i++) {
		if (col == a[i]) return false;
		if ((row - col) == (i - a[i])) return false;
		if ((row + col) == (i + a[i])) return false;
	}
	return true;
}

void gen(int row) {
	if (row == 8) {
		if (cnt == 8) ans++;
		return;
	}
	for (int col = 0; col < 8; col++) {
		if (matrix[row][col] == '.' && survive(row, col)) {
			a[row] = col;
			cnt++;
			gen(row + 1);
			cnt--;
		}
	}
}

int main()
{
	for (int i = 0; i < 8; i++)
		cin >> matrix[i];
	gen(0);
	cout << ans;
	return 0;
}