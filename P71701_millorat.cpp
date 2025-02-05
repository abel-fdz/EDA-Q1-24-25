#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> Vec;
typedef vector<Vec> Mat;

void next(int i, int j, int n, int& ni, int& nj) {
	if (j < n - 1) {
		ni = i;
		nj = j + 1;
	} else {
		ni = i + 1;
		nj = 0;
	}
}

const int N_DIRS = 8;
const int DI[N_DIRS] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int DJ[N_DIRS] = {0, -1, -1, -1, 0, 1, 1, 1};

bool ok(int i, int j, int n) {
	return 0 <= i and i < n and 0 <= j and j < n;
}

bool safe(int i, int j, int n, Mat& m) {
	for (int k = 0; k < 8; ++k) {
		int ii = i + DI[k];
		int jj = j + DJ[k];
		if (ok(ii, jj, n) and m[ii][jj]) return false;
	}
	return true;
}

void escriu(int n, const Mat& m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (m[i][j]) cout << 'K';
			else cout << '.';
		cout << endl;
	}
	cout << "----------" << endl;
}

void search(int i, int j, int n, int r, int sol, Mat& m) {
	if (sol == r) 
		escriu(n, m);
	else if (i != n) {
		int ni, nj;
		next(i, j, n, ni, nj);
		if (safe(i, j, n, m)) {
			m[i][j] = true;
			search(ni, nj, n, r, sol + 1, m);
		}
		m[i][j] = false;
		search(ni, nj, n, r, sol, m);
	}
}

int main(void) {
	int n, r;
	cin >> n >> r;
	Mat m(n, Vec(n, false));
	search(0, 0, n, r, 0, m);
}
