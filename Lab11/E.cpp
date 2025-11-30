#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct DSU{
    vector<int> par, sz;

    DSU(int n) : par(n + 1), sz(n + 1, 1){
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }

    int find(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if (a == b){
            return false;
        }

        if (sz[a] < sz[b]){
            swap(a, b);
        }

        par[b] = a;
        sz[a] += sz[b];



        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);


    for (int i = 0; i < m; ++i){
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    DSU dsu(n);
    vector<int> answ(n);

    vector<bool> active(n + 1, false);

    int comp = 0; //components

    for (int v = n; v >= 1; --v){
        active[v] = true;
        comp++;

        for (int u : g[v]) {
            if (active[u]) {
                if (dsu.unite(v, u)){
                    comp--;
                }
            }
        }

        answ[v - 1] = comp;
    }

    for (int i = 1; i < n; ++i)
        cout << answ[i] << endl;
    cout << 0 << endl;

    return 0;
}