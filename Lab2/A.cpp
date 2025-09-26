#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        dq.push_back(x);
    }

    int k;
    cin >> k;

    int index = 0;
    int min = abs(dq[0] - k);

    for (int i = 1; i < dq.size(); i++){
        int diff = abs(dq[i] - k);
        if (diff < min) {
            min = diff;
            index = i;
        }
    }
    cout << index << endl;
}