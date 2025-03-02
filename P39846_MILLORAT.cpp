#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

const int N_DIRS = 4;
const int di[N_DIRS] = {1, 0, -1, 0};
const int dj[N_DIRS] = {0, 1, 0, -1};

struct Pos {
	int i, j;
	Pos(int ii = -1, int jj = -1) : i(ii), j(jj) {}
};

bool ok(int n, int m, int i, int j) {
	return 0 <= i and i < n and 0 <= j and j < m;
}

int search(const vector<vector<char>>& map, int n, int m, int i0, int j0) {
	const int MINFTY = -1;
	vector<vector<int>> dist(n, vector<int>(m, MINFTY));
	queue<Pos> q;
	int max_dist = MINFTY;
	q.push(Pos(i0, j0));
	dist[i0][j0] = 0;

	while (not q.empty()) {
		Pos p = q.front();
		q.pop();
		int i = p.i;
		int j = p.j;

		for (int k = 0; k < N_DIRS; ++k) {
			int ii = i + di[k];
			int jj = j + dj[k];

			if (ok(n, m, ii, jj) and map[ii][jj] != 'X' and dist[ii][jj] == MINFTY) {
				q.push(Pos(ii, jj));
				dist[ii][jj] = 1 + dist[i][j];
				if (map[ii][jj] == 't') max_dist = dist[ii][jj];
			}
		}
	}
	return max_dist;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	int f, c;
	cin >> f >> c;
	--f;
	--c;

	int dist = search(map, n, m, f, c);
	if (dist >= 0) 
		cout << "distancia maxima: " << dist << endl;
	else 
		cout << "no es pot arribar a cap tresor" << endl;
}
