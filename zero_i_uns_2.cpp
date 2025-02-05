#include <iostream>
#include <vector>
using namespace std;

void write (const vector<bool> & v){
    cout << v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
        cout << " " << v[i];
    cout << endl;
}

void backtracking(vector<bool>& sol, int k, int zeros, int unos){
    // zeros = 3
    // unos = 2
    if (k == sol.size()){   // base case of the recursion
        // cout << "s'escriu la solució";
        write(sol);
    } else {                // inductive case
        //CALEN 3 ZEROS A LA SOLUCIO
        sol[k] = false; // Per posar aquella posició com a visitada per un zero.
        if (zeros > 0) backtracking(sol, k+1, zeros - 1, unos);
        //CALEN 2 UNS A LA SOLUCIO
        sol[k] = true; // Per posar aquella posició com a visitada per un 1.
        if (unos > 0) backtracking(sol, k+1, zeros, unos - 1);
    }
}

int main(){
    int n, o;
    cin >> n >> o;
    vector<bool> sol(n);
    backtracking(sol, 0, n-o, o);
}