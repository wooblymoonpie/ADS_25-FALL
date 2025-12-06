#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const long long INF = INT_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2), y(n + 2);

    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    vector<long long> distance(n + 2, INF);
    vector<bool> used(n, false);

    distance[1] = 0;

    for (int it = 1; it <= n; it++){
        int v = -1;



        for (int i = 1; i <= n; i++){

            if (!used[i] && (v == -1 || distance[i] < distance[v])){
                v = i;
            }
        }

        if (v == -1 || distance[v] == INF){
            break;
        }

        used[v] = true;

        for (int to = 1; to <= n; to++){

            if(used[to] || to == v){
                continue;
            }

            long long w = abs(x[v] - x[to]) + abs(y[v] - y[to]);

            long long mx = max(distance[v], w);

            if (mx < distance[to]){
                distance[to] = mx;
            }
        }
    }

    if(distance[n] >= INT_MAX){
        cout << 0 << endl;
    }

    else{
        cout << distance[n] << endl;
    }



    return 0;
}