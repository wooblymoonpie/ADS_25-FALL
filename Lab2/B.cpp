#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;

    deque<string> dq;
    for(int i = 0; i < n; i++){
        string w;
        cin >> w;
        dq.push_back(w);
    }

    for(int i = 0; i < k; i++){
        dq.push_back(dq.front());
        dq.pop_front();
    }

    for(int i = 0; i < n; i++){
        cout << dq[i] << " ";
    }
    return 0;
} 

