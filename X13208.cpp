#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;

const vector<int> DI = {-1, 0, 1, 0};
const vector<int> DJ = {0, -1, 0, 1};
int dist_total = INT_MAX;

void llegir_mapa(int mida, vector<vector<int>>& tauler){
    int num;
    for (int i = 0; i < mida; ++i){
        for (int j = 0; j < mida; ++j){
            cin >> num;
            tauler[i][j] = num;
        }
    }
    /*
    for (int i = 0; i < mida; ++i){
        for (int j = 0; j < mida; ++j){
            cout << tauler [i][j] << " ";
        }
        cout << endl;
    }
    */
}

bool pos_ok(int i, int j, int r){
    if (i >= 0 and j >= 0 and i <= r and j <= r) return true;
    else return false;
}

void buscar_ruta(int i0, int j0, const vector<vector<int>>& tauler, vector<vector<bool>> tauler_visitats){
    int mida = tauler.size();
    vector<vector<int>> distancies(mida, vector<int>(mida, -1));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({tauler[i0][j0], {i0, j0}});
    distancies[i0][j0] = tauler[i0][j0];

    while (!pq.empty()){
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (i == 0 or j == 0 or i == mida - 1 or j == mida - 1) {
            if (cost < dist_total) {
                dist_total = cost;
            }
        }
        
        for (int k = 0; k < DI.size(); ++k){
            int ii = i + DI[k];
            int jj = j + DJ[k];
            if (pos_ok(ii, jj, mida-1) and !tauler_visitats[ii][jj] and (distancies[ii][jj] == -1 or distancies[ii][jj] > tauler[ii][jj] + cost)){
                distancies[ii][jj] = tauler[ii][jj] + cost;
                pq.push({cost + tauler[ii][jj], {ii, jj}});
            }
        }
    }
}

int main(){
    int mida;
    while (cin >> mida){
        vector<vector<int>> tauler (mida, vector<int>(mida));
        vector<vector<bool>> tauler_visitats (mida, vector<bool>(mida, false));
        llegir_mapa(mida, tauler);
        pair<int, int> p;
        p.first = mida/2;
        p.second = mida/2;
        buscar_ruta(p.first, p.second, tauler, tauler_visitats);
        cout << dist_total << endl;
        dist_total = INT_MAX;
    }
    
}