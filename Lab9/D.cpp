#include <bits/stdc++.h>
using namespace std;

vector<int> compLPS(const string &pattern){
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while(i < n){

        if (pattern[i] == pattern[len])
            lps[i++] = ++len;

        else if (len != 0)
            len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p;
    int n;
    cin >> p >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; ++i)
        cin >> cities[i];

    string p_low = p;
    transform(p_low.begin(), p_low.end(), p_low.begin(), ::tolower);

    int mx = 0;
    vector<pair<string, int>> match;

    for(auto &c : cities){
        string c_low = c;
        transform(c_low.begin(), c_low.end(), c_low.begin(), ::tolower);

        string combined = c_low + "#" + p_low;
        vector<int> lps = compLPS(combined);
        int m = lps[lps.size()-1];

        match.push_back({c, m});
        mx = max(mx, m);
    }

    vector<string> res;
    for(auto &[c, m] : match){
        if (m == mx && m > 0) res.push_back(c);
    }

    cout << res.size() << endl;
    for (auto &c : res)
        cout << c << "\n";

    return 0;
}