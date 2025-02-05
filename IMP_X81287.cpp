#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

using vertex = int;
using graph = vector<vector<pair<vertex,int>>>;// for the adjacency list of a weighted directed graph
using P = pair<int,vertex>; //cost, vertex
int cost_final = INT_MAX;

int dijkstra(vertex x, vertex y, const graph& g, const vector<int>& cost_v){
    int n = g.size(); // num vertexs
    vector<int> D(n, INT_MAX); //on guardem distàncies
    vector<bool> marked(n,false); //for the visited vertices

    D[x] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({D[x], x});

    while (not pq.empty()){
        
        vertex u = pq.top().second; // u = vèrtex que mirem
        int d = pq.top().first;
        pq.pop();
        if (u == y) return D[u] - cost_v[y];
        

        if (not marked[u]){
            marked[u] = true;
            for (auto i : g[u]){ // Mirem tots els vèrtexs adjacents a u, que són: v2, cost
                vertex neigh = i.first; // vertex vei
                int w = i.second; // Pes aresta
                int w_i = cost_v[neigh]; // Pes vèrtex vei
                
                if(D[neigh] > D[u] + w + w_i){
                    D[neigh] = D[u] + w + w_i;
                    pq.push({D[neigh], neigh});
                }
            }
        }
    }
    return INT_MAX; // Si no encontramos un camino al destino
}

int main(){
    int n, m, cost; // Num vertexs i arestes
    cin >> n >> m;
    graph g(n); // es fa una matriu o llista de tantes files com vertexs tenim
    vector<int> cost_v(n);
    for (int i = 0; i < n; ++i){
        cin >> cost;
        cost_v[i] = cost;
    } 
    for (int k = 0; k < m; ++k){
        int u, v, c;
        cin >> u >> v >> c; // v1, v2, cost
        g[u].push_back({v,c}); // A la fila u hi va aquest pair (v2, cost_aresta)
        g[v].push_back({u,c});
    }
    vertex x, y;
    while (cin >> x >> y){
        cost_final = dijkstra(x, y, g, cost_v);
        if (x == y) cout << "c(" << x << "," << y << ") = 0" << endl;
        else if (cost_final == INT_MAX ) cout << "c(" << x << "," << y << ") = " << "+oo" << endl;
        else cout << "c(" << x << "," << y << ") = " << cost_final << endl;
    }
}
