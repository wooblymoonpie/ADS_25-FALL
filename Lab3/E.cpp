#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        int p[4];
        for(int j = 0; j < 4; j++)    
            cin >> p[j];

        arr[i] = max(p[2], p[3]);
    }

    sort(arr, arr + n);
    cout << arr[k - 1];
    return 0;
}