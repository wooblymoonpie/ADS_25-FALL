#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, m, qu, l, r, x;
vector<int> g[5005];

vector<int> type(5005, 0);
vector<int> path(40005);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> qu;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;

            if(x == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= qu; i++){
        int y, z;
        cin >> x >> y >> z;

        bool el1, el2, el3;
        el1 = el2 = el3 = 0;

        for(int to : g[x]){
            if(to == y) el1 = 1;
            if(to == z) el2 = 1;
        }
        for(int to : g[y]){
            if(to == z) el3 = 1;
        }

        if(el1 && el2 && el3) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}