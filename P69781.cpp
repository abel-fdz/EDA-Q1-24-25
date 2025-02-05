#include <iostream>
#include <map>
using namespace std;

#define long_int unsigned long long

long_int x,y;
map <long_int,long_int> m; // Associarem cada numero a la seva posició en la sequüència.

long_int collatz (long_int n, long_int c=1) {
    if (n > (10e7)) return n; // Per evitar càlculs massa llargs.
    // Si ja havíem posat el número al map, retornem la posició actual menys l'última posició on s'havia trobat aquell número.
    // Així sabem la llargada.
    if (m[n]!=0) return c-m[n];
    // Si no havíem posat el número al map, el posem.
    m[n]=c;
    // Crides recursives.
    if (n%2==0) return collatz(n/2+x,c+1);
    return collatz(n*3+y,c+1);
}

int main () {
    long_int n;
    while (cin >> x >> y >> n) {
        cout << collatz(n) << endl;
        m.clear();
    }
}