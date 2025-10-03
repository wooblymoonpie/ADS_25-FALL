#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node* &root, int val)
{
    if(root == NULL) {
        root = new Node(val);
        return;
    }
    if(val < root->val) insert(root->left, val);
    else if(val > root->val) insert(root->right, val);
}

int diam = 0; //diameter

int depth(Node* root)
{
    if(root == NULL) return 0;
    int L = depth(root->left);
    int R = depth(root->right);
    diam = max(diam, L + R);
    return 1 + max(L, R);
}

int main(){
    int n, x;
    cin >> n;

    Node* root = NULL;
    for(int i = 0; i < n; i++) cin >> x, insert(root, x);

    depth(root);
    cout << diam + 1 << "\n";



    return 0;
}