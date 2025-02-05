#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(int n) {
    vector<vector<pair<int, int>>> G(n); // Llista d'adjacència: {cost, vertex}
    vector<bool> vis(n, false);         // Vector per marcar els vèrtexs visitats

    // Llegim el nombre d'arestes i la suma dels costos totals
    int m;
    cin >> m;
    int total = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        total += c;
        G[x].push_back({c, y});
        G[y].push_back({c, x});
    }

    int cost = 0, size = 1;
    vis[0] = true; // Comencem des del vèrtex 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    // Afegim totes les arestes del vèrtex inicial (0)
    for (auto p : G[0]) Q.push(p);

    while (size < n) {
        pair<int, int> p = Q.top();
        Q.pop();
        int u = p.second; // Vèrtex de destinació
        int c = p.first;  // Cost de l'aresta

        if (!vis[u]) { // Només processar si el vèrtex no ha estat visitat
            vis[u] = true;
            ++size;
            cost += c;

            // Afegim totes les arestes sortints del vèrtex u
            for (auto edge : G[u]) Q.push(edge);
        }
    }

    return total - cost; // Retornem l'estalvi màxim
}

int main() {
    int n;
    while (cin >> n) {
        cout << prim(n) << endl;
    }
}
