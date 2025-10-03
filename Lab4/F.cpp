#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void ins(Node* &root, int val){
    if(root == NULL)
    {
        root = new Node(val);
        return;
    }
    else
    {
        if(val < root->val) ins(root->left, val);
        else ins(root->right, val);
    }
}

int sum = 0;

void travel(Node* &cur){
    if(cur == NULL) return;
    else
    {
        if(cur->left != NULL && cur->right != NULL) sum++;
        travel(cur->left);
        travel(cur->right);
    }
}

int main(){

    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        ins(root, x);
    }
    
    travel(root);
    cout << sum << endl;
    


    
    return 0;
}