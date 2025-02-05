#include <iostream>
#include <map>
using namespace std;


int main() {
map<string, int> M;
char c;
while (cin >> c) {
    if (c == 'N') {
        cout << "number: " << M.size() << endl;
    }
    else if (c == 'D') {
        string nif;
        int money;
        cin >> nif >> money;
        M[nif] += money;
    }
    else if (c == 'Q') {
        string nif;
        cin >> nif;
        auto it = M.find(nif);
        if (it == M.end()) cout << -1 << endl;
        else cout << it->second << endl;
    }
    else if (c == 'P') {
    if (M.empty()) return; // Verificar si M está vacío para evitar errores

    auto it2 = M.end();
    --it2; // Apuntar al último elemento de M

    for (auto it = M.begin(); it != M.end(); ++it) {
        const auto& elem = *it;
        const string& key = elem.first;

        // Comprobar si la clave tiene al menos 2 caracteres antes de acceder al penúltimo
        if (key.size() < 2) {
            cerr << "Error: clave demasiado corta" << endl;
            continue;
        }

        int fi = key[key.size() - 2] - '0'; // Convertir el penúltimo carácter a número

        // Comprobar si es el último elemento
        if (fi % 2 == 0 && it != it2) {
            cout << key << " ";
        } else {
            cout << key << endl;
        }
    }
}


    else { // c == ’L’
        if (M.size () < 1) cout << "NO LAST NIF" << endl;
        else {
        auto it = M.begin ();
            ++it ;
            cout << it->first << ' ' << it->second << endl;
        }
    }
}
}