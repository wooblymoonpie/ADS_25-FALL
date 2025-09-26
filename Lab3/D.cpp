#include <iostream>
#include <algorithm>
using namespace std;

int low(int* arr, int n, int x){
    int l = 0;
    int r = n;

    while(l < r){
        int mid = l + (r - l) / 2;
        if(arr[mid] >= x)
            r = mid;     
        else
            l = mid + 1;
    }
    return l;
}

int up(int* arr, int n, int x){
    int l = 0;
    int r = n;

    while(l < r){
        int mid = l + (r - l) / 2;
        if(arr[mid] <= x)
            l = mid + 1; 
        else
            r = mid;    
    }
    return l - 1; 
}

int answ(int* arr, int n, int l, int r){ //getting answer
    return up(arr, n, r) - low(arr, n, l) + 1;
}

int main(){
    int n;
    int q;
    cin >> n >> q;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int l1, r1;
    int l2, r2;
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = 0;

        if(l1 >= l2 && l1 <= r2) 
            ans = answ(arr, n, min(l1, l2), max(r1, r2));
        else if(l2 >= l1 && l2 <= r1) 
            ans = answ(arr, n, min(l1, l2), max(r1, r2));
        else 
            ans = answ(arr, n, l1, r1) + answ(arr, n, l2, r2);
        cout << ans << endl;
    }
}
