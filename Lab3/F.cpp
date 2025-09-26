#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int cnt[1001] = {0};
    int sumP[1001] = {0};

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        cnt[x]++;
        sumP[x] += x;
    }
    for(int i = 1; i <= 1000; i++){
        cnt[i] += cnt[i-1];
        sumP[i] += sumP[i-1];
    }

    int P;
    cin >> P;
    for (int i = 0; i < P; i++){
        int m;
        cin >> m;
        if (m > 1000) m = 1000; // >1000
        cout << cnt[m] << " " << sumP[m] << endl;
    }
    return 0;


}
