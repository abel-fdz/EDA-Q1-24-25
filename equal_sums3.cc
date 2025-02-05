#include <iostream>
#include <vector>
using namespace std;

// Función para escribir una solución
void escriure_sol(const vector<bool>& v_aux, const vector<int>& x) {
    bool first = true;
    cout << "{";
    for (int i = 0; i < v_aux.size(); ++i) {
        if (v_aux[i]) {
            if (!first) cout << ",";
            cout << x[i];
            first = false;
        }
    }
    cout << "}" << endl;
}

// Función de backtracking
void backtrack(int k, int part_sum, vector<bool>& sol, const vector<int>& x, int s, int rest_sum) {
    if (part_sum > s) return; // Poda: ya excedimos la suma deseada
    if (part_sum + rest_sum < s) return; // Poda: no podemos alcanzar la suma deseada

    if (k == x.size()) { // Caso base: hemos procesado todos los elementos
        if (part_sum == s) escriure_sol(sol, x);
    } else {
        // No incluir el elemento x[k]
        sol[k] = false;
        backtrack(k + 1, part_sum, sol, x, s, rest_sum - x[k]);

        // Incluir el elemento x[k]
        sol[k] = true;
        backtrack(k + 1, part_sum + x[k], sol, x, s, rest_sum - x[k]);
    }
}

int main() {
    int s;
    cin >> s;

    vector<int> x;
    int num;
    while (cin >> num) x.push_back(num);

    int rest_sum = 0;
    for (int i = 0; i < x.size(); ++i) rest_sum += x[i];

    vector<bool> sol(x.size(), false);
    backtrack(0, 0, sol, x, s, rest_sum);

    return 0;
}
