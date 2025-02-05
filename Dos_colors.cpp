// Forest
#include<iostream>
#include<vector>

using namespace std;
using VVI = vector<vector<int>>; // matriu
using VB = vector<bool>;
using VI = vector<int>;

bool comprovacio_de_cada_cc(const VVI& g, int v, VB& visited, VI& father){ 
    
}

bool count_trees(const VVI& g){ // Ens passem la matriu
    int n = g.size(); // numero de files de la matriu
    VB visited(n, false); // es crea un vector de n boleans amb valor false (Representa cada vèrtex)
    VI father(n, -1); // es crea un vector ne n integers amb valor -1 (Representa cada vèrtex)
    for (int v = 0; v < n; ++v){ // Es fa tantes iteracions com vèrtexs tenim
        if (not visited[v]){
            if (comprovacio_de_cada_cc(g, v, visited,father)) return false; // Es fa la comprovació del vèrtex v.
        }
    }
    return true;
}

int main(){ // Hem de mirar si per cada component connexa del graf, es poden pintar les components tal que cap veí es pinti del mateix color.
    int n, m;
    while (cin >> n >> m){
        VVI g(n);
        for (int k = 0; k < m; ++k){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v); // A la fila u afegim v
            g[v].push_back(u); // A la fila v afegim u
        }
        bool dos_colors = count_trees(g); // -1 if g is not a tree
        if (dos_colors == false) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}