#include <iostream>
#include <vector>
using namespace std;

bool spl(const vector<long long> &a, int k, long long mid){
    int blocks = 1;
    long long sum = 0;

    for(long long x : a){

        if (sum + x > mid){
            blocks++;
            sum = x;
        }
        else{
            sum += x;
        }
    }

    return blocks <= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sumA = 0, maxA = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sumA += a[i];
        if (a[i] > maxA) maxA = a[i];
    }

    long long l = maxA, r = sumA, ans = sumA;
    while(l <= r){
        long long mid = (l + r) / 2;
        if (spl(a, k, mid)){
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
