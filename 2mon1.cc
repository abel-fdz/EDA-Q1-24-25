// Two coins of each kind (1)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using VI = vector<int>;

int x, n;
VI coins;

void write (const vector<bool> & v){
    cout << x << " = ";
    bool first = true;
    for (size_t i = 0; i < v.size(); ++i){
        if (v[i] != 0){
            if (first) first = false;
            else cout << " + ";
            cout << coins[i];
            if (i%2 == 1) cout << 'p';
        }
    }
    cout << endl;
}

void backtrack(vector<bool>& sol, int k, int part_sum){
    int n = sol.size();
    if (part_sum > x) return;
    if (k == n){
        if (x == part_sum) write(sol);
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
        backtrack(sol, 0, 0);
        cout << "----------" << endl;
    }
}
