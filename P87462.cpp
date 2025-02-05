#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<int> DH = {0, -1, 0, 1};
const vector<int> DV = {1, 0, -1, 0};
const vector<pair<int, int>> diagonal = {{0,1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};

bool bfs(const vector<vector<char>>& map, int i0, int j0){
    // Queue + Matriu Visitats + Distàncies si calen (NO)
    int files = map.size();
    int columnes = map[0].size();

    queue<pair<int,int>> q;
    q.push({i0, j0});

    vector<vector<bool>> visited(files, vector<bool>(columnes, false));
    visited[i0][j0] = true;

    for (int k = 0; k < 4; ++k){
        int i_inici = q.front().first + DH[k];
        int j_inici = q.front().second + DV[k];
        if (map[i_inici][j_inici] == 'F') return false;
    }

    while (!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        visited[i][j] = true;

        // Visitem totes les adjacents i mirem si hi ha algo, sino, les afegim si es pot.

        for (int k = 0; k < 4; ++k){
            int ni = i + DH[k];
            int nj = j + DV[k];
            if (ni >= 0 and nj >= 0 and ni < files and nj < columnes and map[ni][nj] != 'X' and visited[ni][nj] == false){
                // Comprovem que la casella següent no tingui un F aprop.
                if (map[ni][nj] == 'B') return true;
                else q.push({ni, nj});
            }
        }
    }
    return false;
}

int main(){
    int f, c;
    while (cin >> f >> c){
        pair<int, int> pos_ini;
        vector<vector<char>> map(f, vector<char>(c));
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                char x;
                cin >> x;
                map[i][j] = x;
                if (x == 'P') pos_ini = {i, j};
            }
        }
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                if (map[i][j] == 'F'){
                    for (int z = 0; z < diagonal.size(); ++z){
                        if (map[i + diagonal[z].first][j + diagonal[z].second] != 'F') map[i + diagonal[z].first][j + diagonal[z].second] = 'X'; 
                    }
                }
            }
        }
        /*
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                cout << map[i][j];
            } cout << endl;
        }
        */
        
        if (map[pos_ini.first][pos_ini.second] == 'X') cout << "no" << endl; 
        else if (bfs(map, pos_ini.first, pos_ini.second)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}