#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<bool>& v_aux, const vector<int>& x){
    int cont = 0;
    for (int i = 0; i < v_aux.size(); ++i) if (v_aux[i] == true) ++cont;
    --cont;
    cout << "{";
    for (int i = 0; i < x.size(); ++i){
        if (v_aux[i] == true && cont != 0){
            cout << x[i] << ",";
            --cont;
        } 
        else if (v_aux[i] == true) cout << x[i];
    } 
    cout << "}";
    cout << endl;
}

void backtrack(int k, int part_sum, vector<bool>& sol, vector<int>& x, int s){
    if (k == x.size()) {
        if (part_sum == s) escriure_sol(sol, x);
    }
    else {
        sol[k] = false;
        backtrack(k+1, part_sum, sol, x, s); // Aquest ens assegura que recorrem tots els elements 
        sol[k] = true;
        backtrack(k+1, part_sum + x[k], sol, x, s); // 
    }
}


int main(){
    int s;
    int comb;
    cin >> s >> comb;
    int num;
    vector<int> x;
    while (cin >> num) x.push_back(num);
    vector<bool> used(comb, false);
    backtrack(0, 0, used, x, s);
}