#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int a[1000];      
    int freq[1001] = {}; // a_i <= 1000

    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    int max = 0; //maz freq
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] > max) {
            max = freq[i];
        }
    }
    for (int i = 1000; i >= 1; i--) {
        if (freq[i] == max) {
            cout << i << " ";
        }
    }
    return 0;
}