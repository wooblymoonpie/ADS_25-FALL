#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long n, g[505][505], a[505], used[505], current, answ[505];
int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
    
        for(int j = 1; j <= n; j++){

            cin >> g[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        int v = a[i];

        used[v] = 1;
        current = 0; 

        for(int j = 1; j <= n; j++){


            for(int k = 1; k <= n; k++){


                if(g[j][v] + g[v][k] < g[j][k]){
                    g[j][k] = g[j][v] + g[v][k];
                }
            }
        }


        for(int j = 1; j <= n; j++){
            if(used[j]){
                for(int k = 1; k <= n; k++){

                    if(used[k] && current < g[j][k]){ 
                    current = g[j][k];
                    }
                }
            }

        answ[i] = current;
    }
    }

    for(int i = 1; i <= n; i++){
        cout << answ[i] << endl;
    }





    return 0;
}