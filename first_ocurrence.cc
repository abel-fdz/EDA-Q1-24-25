#include <iostream>
#include <vector>
using namespace std;

int dicotomic(int x, int l, int r, const vector<double>& v){
    if (l > r) return -1;
    int med = (l + r)/2;
    // CAS BASE
    if (v[med] == x) return med; 
    // HIPÒTESI D'INDUCCIÓ
    else if (v[med] > x) return dicotomic (x, l, med - 1, v);
    else if (v[med] < x) return dicotomic (x, med + 1, r, v);
    
    return -1;
}

int first_occurrence(double x, const vector<double>& v){
    return dicotomic(x, 0, v.size()-1, v);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
