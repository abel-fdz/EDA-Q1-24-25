#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DIST_MAX = 0;

void dijkstra(int f, int c, const vector<vector<char>>& mapa, vector<vector<bool>>& visited){
    queue<pair<int, int>> q;
    queue<int> dist;
    q.push({f, c});
    dist.push(0);
    int p1, p2, d;

    while (!q.empty()){
        p1 = q.front().first;
        p2 = q.front().second;
        d = dist.front();
        q.pop();
        dist.pop();

        if (mapa[p1][p2] == 't' and not visited[p1][p2]) {
            if (d > DIST_MAX) DIST_MAX = d;
        }
        visited[p1][p2] = true;
        if (not visited[p1+1][p2] and mapa[p1+1][p2] != 'X'){
           q.push({p1 + 1,p2});
           dist.push(d+1); 
        } 
        if (not visited[p1-1][p2] and mapa[p1-1][p2] != 'X'){
            q.push({p1 - 1, p2});
            dist.push(d+1);
        } 
        if (not visited[p1][p2+1] and mapa[p1][p2+1] != 'X'){
            q.push({p1, p2+1});
            dist.push(d+1);
        } 
        if (not visited[p1][p2-1] and mapa[p1][p2-1] != 'X'){
            q.push({p1, p2-1});
            dist.push(d+1);
        } 
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n + 2, vector<char>(m + 2));
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
    for (int i = 0; i < n + 2; ++i){
        for (int j = 0; j < m + 2; ++j){
            char c;
            if (i == 0 or j == 0 or i == n + 1 or j == m + 1) mapa[i][j] = 'X';
            else {
                cin >> c;
                mapa[i][j] = c;
            } 
        }
    }
    int f, c;
    cin >> f >> c;
    dijkstra(f, c, mapa, visited);
    // Comprovació que s'ha fet bé
    if (DIST_MAX != 0) cout << "distancia maxima: " << DIST_MAX << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
    /*for (int i = 0; i < n + 2; ++i){
        for (int j = 0; j < m + 2; ++j){
            cout << mapa[i][j];
        }
        cout << endl;
    }*/
}