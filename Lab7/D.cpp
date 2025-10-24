#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct person{
    string name;
    string surname;
    double gpa;
};

bool cmp (person a, person b){

    if(a.gpa != b.gpa){
        return a.gpa < b.gpa;
    }

    if(a.surname != b.surname){
        return a.surname < b.surname;
    }

    return a.name < b.name;
}

int main(){
    int n, m;
    person p[1000005];
    double x;
    string s;
    
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> p[i].surname >> p[i].name >> m;
        int cred_sum = 0; double gpa_sum = 0;
        for(int j = 1; j <= m; j++){
            cin >> s >> x;
            if(s == "A+") gpa_sum += (4.0 * x);
            if(s == "A") gpa_sum += (3.75 * x);
            if(s == "B+") gpa_sum += (3.5 * x);
            if(s == "B") gpa_sum += (3.0 * x);
            if(s == "C+") gpa_sum += (2.5 * x);
            if(s == "C") gpa_sum += (2.0 * x);
            if(s == "D+") gpa_sum += (1.5 * x);
            if(s == "D") gpa_sum += (1.0 * x);
            if(s == "F") gpa_sum += (0 * x);
            
            cred_sum += x;
        }
        p[i].gpa = gpa_sum / double(cred_sum);
    }
    sort(p + 1, p + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        cout.precision(3);
        
        cout << p[i].surname << ' ' << p[i].name << ' ' << fixed << p[i].gpa << '\n';
    }
    
    return 0;
}