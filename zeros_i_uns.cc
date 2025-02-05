#include <iostream>
using namespace std;

void write (const vector<bool> & v){
    cout << v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
        cout << " " << v[i];
    cout << endl;
}

void backtracking(vector<bool>& sol, int k){
    if (k == sol.size()){   // base case of the recursion
        write(sol);
    } else {    // inductive case
        sol[k] = false;
        backtracking(sol, k+1);
        sol[k] = true;
        backtracking(sol, k+1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> sol(n);
    backtracking(sol, 0);
}