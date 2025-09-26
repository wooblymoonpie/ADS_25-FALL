#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = s[i-1] + a[i];

    for (int i = 0; i < m; i++){
        long long x;
        cin >> x;
        int b = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
        cout << b << endl;
    }

    return 0;
}
