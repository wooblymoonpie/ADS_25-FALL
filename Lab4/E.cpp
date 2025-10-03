#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, x, y, z;
vector<int> graph[1005];
int lvl[1005], mx = INT_MIN;

int main() {
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        cin >> x >> y >> z;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    memset(lvl, -1, sizeof(lvl));
    lvl[1] = 0;
    queue<int> q;
    map<int, int> mp;
    q.push(1);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto to : graph[u]){
            if(lvl[to] == -1){
                q.push(to);
                lvl[to] = lvl[u] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        mp[lvl[i]]++;
        mx = max(mx, mp[lvl[i]]);
    }
    
    cout << mx;
    return 0;
}