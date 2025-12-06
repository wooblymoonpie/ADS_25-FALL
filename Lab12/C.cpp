#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int INF = 1e9;
int n, m;

bool k[405][405];

int bfs(bool ok){
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        int v = q.front();
        q.pop();


        for (int to = 1; to <= n; ++to) {
            if (to == v) continue;

            bool check;
            if(ok){
                check = k[v][to];
            }

            else{
                check = !k[v][to];
            }

            if (check && dist[to] == INF){
                dist[to] = dist[v] + 1;

                q.push(to);
            }
        }
    }

    return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;


        k[u][v] = k[v][u] = true;
    }

    int high = bfs(true);
    int low  = bfs(false);

    if(high == INF || low == INF){
        cout << -1 << endl;
    } 


    else{
        cout << max(high, low) << endl;
    }




    return 0;
}