#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left = 0;
    long long sum = 0;
    int minLen = 1000000;

    for (int right = 0; right < n; right++){
        sum += a[right];

        while (sum >= k){
            minLen = min(minLen, right - left + 1);
            sum -= a[left];
            left++;
        }
    }
    cout << minLen << endl;
    return 0;
}
