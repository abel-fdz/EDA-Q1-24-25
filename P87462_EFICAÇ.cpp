#include <iostream>
#include <vector>
using namespace std;

// Direcciones para moverse en líneas rectas
vector<pair<int, int>> move_dirs = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

// Direcciones para moverse en todas las direcciones (incluyendo diagonales)
vector<pair<int, int>> all_dirs = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

// Comprobar si una posición es segura
bool safe_pos(const vector<vector<char>>& M, int i, int j) {
    for (auto& d : all_dirs) {
        int ni = i + d.first;
        int nj = j + d.second;
        if (ni >= 0 && nj >= 0 && ni < M.size() && nj < M[0].size()) {
            if (M[ni][nj] == 'F') return false;
        }
    }
    return true;
}

// Comprobar si una posición es alcanzable
bool reachable(vector<vector<char>>& M, int i, int j) {
    if (M[i][j] == 'X') return false;
    if (!safe_pos(M, i, j)) return false;
    if (M[i][j] == 'B') return true;

    M[i][j] = 'X'; // Marcar como visitado

    for (auto& d : move_dirs) {
        int ni = i + d.first;
        int nj = j + d.second;
        if (ni >= 0 && nj >= 0 && ni < M.size() && nj < M[0].size()) {
            if (reachable(M, ni, nj)) return true;
        }
    }
    return false;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        vector<vector<char>> M(f, vector<char>(c));
        int ini_i = -1, ini_j = -1;

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> M[i][j];
                if (M[i][j] == 'P') {
                    ini_i = i;
                    ini_j = j;
                }
            }
        }

        if (reachable(M, ini_i, ini_j)) {
            cout << "si" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
