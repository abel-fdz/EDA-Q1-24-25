#include <iostream>
#include <map>
#include <string>
using namespace std;

void back(int n, int k, int uns, int dos, int tres, string& sol_parcial, bool consecutiu){
    if (k == n*3){
        if (consecutiu) cout << sol_parcial << endl;
    } else {
        if (uns < n and (consecutiu == false or sol_parcial[k-1] != '1')){
            sol_parcial.push_back('1');
            back(n, k+1, uns + 1, dos, tres, sol_parcial, consecutiu or (k > 0 and sol_parcial[k-1] == '1'));
            sol_parcial.pop_back();
        } 
        if (dos < n and (consecutiu == false or sol_parcial[k-1] != '2')){
            sol_parcial.push_back('2');
            back(n, k+1, uns, dos + 1, tres, sol_parcial, consecutiu or (k > 0 and sol_parcial[k-1] == '2'));
            sol_parcial.pop_back();
        }  
        if (tres < n and (consecutiu == false or sol_parcial[k-1] != '3')){
            sol_parcial.push_back('3');
            back(n, k+1, uns, dos, tres + 1, sol_parcial, consecutiu or (k > 0 and sol_parcial[k-1] == '3'));
            sol_parcial.pop_back();
        }
    }
}


int main() {
    int n;
    while (cin >> n){
        string s;
        back(n, 0, 0, 0, 0, s, false);
        cout << "**********" << endl;
    }
}