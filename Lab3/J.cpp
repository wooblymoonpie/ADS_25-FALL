#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool enough(const vector<long long>& bags, long long K, long long H){
    long long hours = 0;
    for (long long bars : bags){
        hours += (bars + K - 1) / K; 
        if (hours > H){
            return false; 
        }
    }
    return hours <= H;
}

int main(){
    int N;           
    long long H;     
    cin >> N >> H;

    vector<long long> bags(N);
    for (int i = 0; i < N; i++) {
        cin >> bags[i]; 
    }

    long long left = 1; 
    long long right = *max_element(bags.begin(), bags.end()); 
    long long answer = right;

    while (left <= right){
        long long mid = (left + right) / 2;
        if (enough(bags, mid, H)){
            answer = mid;     
            right = mid - 1;
        }
        else{
            left = mid + 1;    
        }
    }

    cout << answer << endl;
    return 0;
}
