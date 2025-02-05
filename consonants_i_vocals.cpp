#include <iostream>
#include <string>
#include <vector>
using namespace std;

void write(vector<char>& sol){
    for (auto it: sol){
        cout << it;
    } cout << endl;
}

void backtrack(vector<char>& sol, int k, string cons, string voc, vector<bool>& used_voc, vector<bool>& used_cons){
    if (sol.size() == k){
        write (sol);
    } else {
        if (k % 2 == 0){
            for (int i = 0; i < cons.size(); ++i){
                if (not used_cons[i]){
                    used_cons[i] = true;
                    sol[k] = cons[i];
                    backtrack(sol, k + 1, cons, voc, used_voc, used_cons);
                    used_cons[i] = false;

                }
            }
        } else {
            for (int i = 0; i < voc.size(); ++i){
                if (not used_voc[i]){
                    used_voc[i] = true;
                    sol[k] = voc[i];
                    backtrack(sol, k + 1, cons, voc, used_voc, used_cons);
                    used_voc[i] = false;

                }
            }
        }
        
    }
}

int main(){
    int n;
    cin >> n;
    string cons, voc;
    cin >> cons >> voc;
    vector<bool> used_voc(n, false);
    vector<bool> used_cons(n, false);
    vector<char> sol(n*2);
    backtrack(sol, 0, cons, voc, used_voc, used_cons);

}