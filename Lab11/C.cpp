#include <bits/stdc++.h>
using namespace std;

struct E{ //edge
    long long to;
    long long w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, x, y, a, b, c;

    cin >> n >> m;
    cin >> x >> y;

    vector<vector<E>> g(n + 1);

    for (int i = 0; i < m; i++) {
        string type;
        long long cost;

        cin >> type >> a >> b >> c;

        if (type == "big")
            cost = 1ll * x * c;
        else if (type == "small")
            cost = 1ll * y * c;
        else
            cost = 1ll * min(x, y) * c;

        g[a].push_back({b, cost});
        g[b].push_back({a, cost});
    }

    vector<bool> us(n + 1, false); //used
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    pq.push({0, 1});
    long long obshee = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (us[v]) continue;
        us[v] = true;
        obshee += w;

        for (auto &e : g[v])
        {
            if (!us[e.to]){
                pq.push({e.w, e.to});
            }
        }
    }

    cout << obshee << endl;
    return 0;
}