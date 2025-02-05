#include <iostream>
#include <vector>
using namespace std;

// Define los caracteres candidatos
const vector<char> candidates = {'A', 'C', 'G', 'T'};

// Función para obtener el carácter opuesto
char oposat(char c) {
    if (c == 'A') return 'T';
    else if (c == 'T') return 'A';
    else if (c == 'G') return 'C';
    else return 'G';
}

// Función recursiva para generar las soluciones
void escriu(vector<char>& A, vector<char>& B, int i) {
    int n = A.size();
    if (i == n) {
        for (char x : A) cout << x;
        cout << endl;
        for (char x : B) cout << x;
        cout << endl << endl;
    } else {
        // Ambos caracteres están definidos, verifica que sean opuestos
        if (A[i] != '.' && B[i] != '.' && oposat(A[i]) != B[i]) return;

        // Ambos caracteres son vacíos
        else if (A[i] == '.' && B[i] == '.') {
            for (char c : candidates) {
                A[i] = c;
                B[i] = oposat(c);
                escriu(A, B, i + 1);
                A[i] = B[i] = '.'; // Restaurar para el backtracking
            }
        }

        // Solo A[i] está definido
        else if (A[i] != '.') {
            char old = B[i];
            B[i] = oposat(A[i]);
            escriu(A, B, i + 1);
            B[i] = old; // Restaurar para el backtracking
        }

        // Solo B[i] está definido
        else {
            char old = A[i];
            A[i] = oposat(B[i]);
            escriu(A, B, i + 1);
            A[i] = old; // Restaurar para el backtracking
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<char> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        escriu(A, B, 0);
        cout << string(10, '-') << endl;
    }
}
