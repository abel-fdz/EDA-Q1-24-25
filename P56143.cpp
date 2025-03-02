#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int INF = numeric_limits<int>::max();
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void escriu_cami(vector<vector<char>>& T, int i_ini, int j_ini) {
    int f = T.size();
    int c = T[0].size();
    vector<vector<int>> dist(f, vector<int>(c, INF));
    vector<vector<pair<int, int>>> previ(f, vector<pair<int, int>>(c));
    queue<pair<int, int>> Q;

    dist[i_ini][j_ini] = 0;
    Q.push({i_ini, j_ini});
    bool trobat = false;
    int i_pages, j_pages;

    while (not Q.empty() and not trobat) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();

        for (auto& d : dirs) {
            int ni = i + d.first;
            int nj = j + d.second;

            if (ni >= 0 && ni < f && nj >= 0 && nj < c && T[ni][nj] != 'X' && dist[ni][nj] == INF) {
                if (T[ni][nj] == 'F') {
                    i_pages = ni;
                    j_pages = nj;
                    trobat = true;
                }
                dist[ni][nj] = dist[i][j] + 1;
                previ[ni][nj] = {i, j};
                Q.push({ni, nj});
            }
        }
    }

    if (!trobat) {
        cout << 0 << endl;
    } else {
        cout << dist[i_pages][j_pages] + 1 << " ";

        // Reconstruct path
        pair<int, int> current = {i_pages, j_pages};
        pair<int, int> goal = {i_ini, j_ini};
        vector<pair<int, int>> cami;

        while (current != goal) {
            cami.push_back(current);
            current = previ[current.first][current.second];
        }
        cami.push_back(goal);

        // Write path in reversed order
        for (int i = cami.size() - 1; i >= 0; --i) {
            if (i != 0) cout << " " << cami[i].first << " " << cami[i].second << " ";
            else cout << " " << cami[i].first << " " << cami[i].second;
        }
        cout << endl;
    }
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        vector<vector<char>> T(f, vector<char>(c));
        int i_ini = -1, j_ini = -1;

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> T[i][j];
                if (T[i][j] == 'K') {
                    i_ini = i;
                    j_ini = j;
                }
            }
        }

        escriu_cami(T, i_ini, j_ini);
    }
}
