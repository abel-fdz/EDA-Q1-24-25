// Two coins of each kind (1)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using VI = vector<int>;

int x, n;
VI coins;


int vegades = 0;

void suma (const vector<bool> & v){
    ++vegades;
}

int backtrack(vector<bool>& sol, int k, int part_sum, vector<int>& atemptat){
    int n = sol.size();
    if (part_sum > x) return;
    if (k == n){
        return (part_sum == x)
    }
    else{
        sol[k] = true;
        backtrack(sol, k+1, part_sum + coins[k]);
        sol[k] = false;
        backtrack(sol, k+1, part_sum);
    }
}

int main(){
    while (cin >> x >> n){
        
        coins = VI(2*n);
        for (int i = 0; i < 2*n; i +=2){
            cin >> coins[i];
            coins[i+1] = coins[i];
        }
        sort(coins.begin(),coins.end());
        vector<bool> sol(2*n, false);
        vector<int>attemptat(2*n, 0);
        backtrack(sol, 0, 0, attemptat);
        cout << vegades << endl;
        vegades = 0;
    }
}
