#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int num_final = 0;

bool comprovacio(string sol_p, vector<int> vec){
    int aux = stoi(sol_p);
    int aux2 = aux;
        for (int z = sol_p.size() - 1; z >= 0; --z){
            for (int h = 0; h < vec.size(); ++h){
                if (aux % vec[h] == 0) return false;
            }
            aux = aux /10;
        }
    num_final = aux2;
    return true;
}


void backtrack(int n, vector<int> vec, string sol_p, int k){
    if (k == n){
        if (comprovacio(sol_p, vec) == true) cout << num_final << endl;
    } else {
        for (int i = 0; i <= 9; ++i){
            if (k >= 1 and comprovacio(sol_p, vec) == true){
                sol_p.push_back(i + '0');
                backtrack(n, vec, sol_p, k + 1);
                sol_p.pop_back();
            } else if (k == 0){
                sol_p.push_back(i + '0');
                backtrack(n, vec, sol_p, k + 1);
                sol_p.pop_back();
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> vec(m);
        for (int i = 0; i < m; ++i){
            int j;
            cin >> j;
            vec[i] = j;
        } 
        vector<int> sol_p(0);
        string s;
        backtrack(n, vec, s, 0);
        cout << "----------" << endl;
    }
}
