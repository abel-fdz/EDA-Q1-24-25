// Permutations of words
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void write (const vector<int> & v, const vector<string>& words){
    cout << '(' << words[v[0]];
    for (int i = 1; i < v.size(); ++i)
        cout << ',' << words[v[i]];
    cout << ')' << endl;
}

void perm(vector<int>& sol, int k, vector<bool> used, const vector<string>& words){
    if (k == sol.size()){
        write(sol, words);
    } else {
        for (int i = 0; i < words.size(); ++i){ // Aquí fem que comenci amb les 3 paraules diferents
            if (not used[i]) {                  // Comprovem que les següents paraules no siguin la que ja hem fet servir
                used[i] = true;                 // Diem que la primera paraula la fem servir
                sol[k] = i;                     // La posem com a solució
                perm(sol, k+1, used, words);    // Busquem la solució de les dues pròximes amb la primera com a solució
                used[i] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n,"");
    for (int i = 0;  i < n; ++i)
        cin >> words[i];
    vector<int> sol(n,0);
    vector<bool> used(n, false);
    perm(sol, 0, used, words);
}