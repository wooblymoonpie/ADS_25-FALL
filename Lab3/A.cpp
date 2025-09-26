#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> qrs(t);
    for(int i = 0; i < t; i++) cin >> qrs[i];

    int n, m;
    cin >> n >> m;
    vector<int> arr(n * m);
    for (int i = 0; i < n * m; i++) cin >> arr[i];

    for (int q = 0; q < t; q++){
        bool found = false;
        for (int idx = 0; idx < n * m; idx++) {
            if (arr[idx] == qrs[q]) {
                int row = idx / m;
                int col = idx % m;
                cout << row << " " << col << endl;
                found = true;
                break;
            }
        }
        if(!found) cout << -1 << endl;
    }

    return 0;
}
