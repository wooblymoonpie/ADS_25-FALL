#include <iostream>
#include <vector>
using namespace std;

bool ok(const vector<int> &a, long long k, long long f){
    long long flights = 0;
    for (int x : a){
        flights += (x + k - 1) / k; 
        if (flights > f) return false;
    }
    return true;
}

int main() {
    int n;
    long long f;
    cin >> n >> f;

    vector<int> a(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > maxVal) maxVal = a[i];
    }

    long long l = 1, r = maxVal;
    long long ans = maxVal;

    while (l <= r){
        long long mid = (l + r) / 2;
        if (ok(a, mid, f)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
