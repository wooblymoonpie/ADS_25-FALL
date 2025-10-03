#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int cnt[5005];

void bt_ins(Node* &root, int val){
    if(root == nullptr) {
        root = new Node(val);
        return;
    }
    else {
        if(val < root->data) bt_ins(root->left, val);
        else bt_ins(root->right, val);
    }
}
int max_lvl = 0;
void hello_hello(Node* root, int lvl){
    if(root == nullptr) return;
    cnt[lvl] += root->data;
    hello_hello(root->left, lvl+1);
    hello_hello(root->right, lvl+1);
    max_lvl = max(max_lvl, lvl);
}

int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x, bt_ins(root, x);
    hello_hello(root, 0);
    
    cout << max_lvl + 1 << endl;
    
    for(int i = 0; i <= max_lvl; i++){
        cout << cnt[i] << ' ';
    }
    
    

    
    return 0;
}