#include <stdio.h>

char board[226];
int X = 0, O = 0;

int isWin(const int x, const int y) {
	const char cmp = board[y * 15 + x];
	if (cmp == '.') return 0;
	// horizontal check if there are 5 same
	int left = x, right = x;
	while (left > 0 && board[y * 15 + left - 1] == cmp) --left;
	while (right < 14 && board[y * 15 + right + 1] == cmp) ++right;
	if (right - left >= 4) return 1;
	// vertical check if there are 5 same
	int up = y, down = y;
	while (up > 0 && board[(up - 1) * 15 + x] == cmp) --up;
	while (down < 14 && board[(down + 1) * 15 + x] == cmp) ++down;
	if (down - up >= 4) return 1;
	// diagonal check if there are 5 same
	left = right = x, up = down = y;
	while (left > 0 && up > 0 && board[(up - 1) * 15 + left - 1] == cmp) --left, --up;
	while (right < 14 && down < 14 && board[(down + 1) * 15 + right + 1] == cmp) ++right, ++down;
	if (right - left >= 4) return 1;

	left = right = x, up = down = y;
	while (left > 0 && down < 14 && board[(down + 1) * 15 + left - 1] == cmp) --left, ++down;
	while (right < 14 && up > 0 && board[(up - 1) * 15 + right + 1] == cmp) ++right, --up;
	if (right - left >= 4) return 1;
	return 0;
}

int willWin(int x, int y) {
	if (board[y * 15 + x] != '.') return 0;
	if (X > O) board[y * 15 + x] = 'O';
	else board[y * 15 + x] = 'X';
	if (isWin(x, y)) {
		board[y * 15 + x] = '.';
		return 1;
	}
	board[y * 15 + x] = '.';
	return 0;
}

int main() {
	int x = -1, y = -1;
	for (int i = 0; i < 15; ++i) scanf("%15s", board + i * 15);
	for (int i = 0; i < 225; ++i) {
		if (board[i] == 'X') ++X;
		else if (board[i] == 'O') ++O;
	}
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j) {
			if (isWin(i, j)) {
				printf("AlreadyWin!");
				return 0;
			}
			if (willWin(i, j) && x == -1) y = i, x = j;
		}
	if (x == -1) printf("CannotWin!");
	else printf("Win!\n%d %d", x + 1, y + 1);
	return 0;
}
