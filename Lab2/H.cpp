#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr){}
};

Node* insert(Node* h, int x, int p){
    Node* newNode = new Node(x);
    if (p == 0){
        newNode->next = h;
        return newNode;
    }
    Node* cur = h;
    for (int i = 0; i < p - 1; i++) cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    return h;
}
Node* remove(Node* h, int p){
    if(!h) return h;
    if(p == 0) {
        Node* tmp = h->next;
        delete h;
        return tmp;
    }
    Node* cur = h;
    for(int i = 0; i < p - 1; i++) cur = cur->next;
    Node* del = cur->next;
    cur->next = del->next;
    delete del;
    return h;
}
void print(Node* h){
    if(!h){
        cout << -1 << endl;
        return;
    }
    Node* cur = h;
    while(cur){
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}
Node* replace(Node* h, int p1, int p2){
    if(!h) return h;
    Node* cur = h;
    Node* prev = nullptr;
    for(int i = 0; i < p1; i++){
        prev = cur;
        cur = cur->next;
    }
    if(!cur) return h;

    if(prev) prev->next = cur->next;
    else h = cur->next;

    if(p2 == 0){
        cur->next = h;
        h = cur;
        return h;
    }
    Node* dest = h;
    for (int i = 0; i < p2 - 1; i++) dest = dest->next;
    cur->next = dest->next;
    dest->next = cur;
    return h;
}
Node* reverseList(Node* h){
    Node* prev = nullptr;
    Node* cur = h;
    while(cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
Node* cyclic_left(Node* h, int x){
    if(!h || !h->next) return h;
    int n = 0;
    Node* cur = h;
    while(cur){
        n++;
        cur = cur->next;
    }
    x %= n;
    if(x == 0) return h;

    Node* t = h;
    for(int i = 1; i < n; i++) t = t->next;
    t->next = h;

    Node* newTail = h;
    for(int i = 1; i < x; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
Node* cyclic_right(Node* h, int x){
    if(!h || !h->next) return h;
    int n = 0;
    Node* cur = h;
    while(cur){
        n++;
        cur = cur->next;
    }
    x %= n;
    return cyclic_left(h, n - x);
}
int main(){
    Node* h = nullptr;
    int cmd;
    while(cin >> cmd){
        if(cmd == 0) break;
        if(cmd == 1){
            int x, p;
            cin >> x >> p;
            h = insert(h, x, p);
        }
        else if(cmd == 2){
            int p;
            cin >> p;
            h = remove(h, p);
        }
        else if(cmd == 3){
            print(h);
        }
        else if(cmd == 4){
            int p1, p2;
            cin >> p1 >> p2;
            h = replace(h, p1, p2);
        }
        else if(cmd == 5){
            h = reverseList(h);
        }
        else if(cmd == 6){
            int x;
            cin >> x;
            h = cyclic_left(h, x);
        }
        else if(cmd == 7){
            int x;
            cin >> x;
            h = cyclic_right(h, x);
        }
    }
    return 0;
}