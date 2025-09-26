#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T; //test
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        queue<char> q;
        int count[26] = {0};
        
        for(int i = 0; i < N; i++){
            char c;
            cin >> c;
            q.push(c);
            count[c - 'a']++;
            
            while(!q.empty() && count[q.front() - 'a'] > 1){
                q.pop();
            }
            
            if(q.empty()) cout << -1 << " ";
            else cout << q.front() << " ";
        }
        cout << endl;
    }
    return 0;
}