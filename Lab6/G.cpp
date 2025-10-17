#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, t;
    map<string, string> mp;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> s >> t;
        bool ok = 0;
        
        for(auto it : mp){
            if(it.second == s){
                mp[it.first] = t; 
                ok = 1;
            }
        }
        if(!ok) mp[s] = t;
    }
    cout << mp.size() << endl;
    
    for(auto it : mp) cout << it.first << ' ' << it.second << endl;
    
    return 0;
}