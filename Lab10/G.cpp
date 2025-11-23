#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg0;

bool topo_remove(int remove){
    vector<int> indeg = indeg0;

    if (remove != -1) {
        if (indeg[remove] != 0) {
            indeg[remove]--;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int process = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        process++;

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return (process == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n, {});
    indeg0.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        indeg0[v]++;
    }

    if (topo_remove(-1)) {
        cout << "YES\n";
        return 0;
    }

    for (int v = 0; v < n; ++v) {
        if (indeg0[v] == 0) continue;

        if (topo_remove(v)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}