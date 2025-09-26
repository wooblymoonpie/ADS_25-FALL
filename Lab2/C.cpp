#include <iostream>
#include <deque>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int main(){
    int m;
    cin >> m;

    Node* h = nullptr; //head
    Node* t = nullptr; //tail

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if(h == nullptr){
            h = newNode;
            t = newNode;
        }
        else{
            t->next = newNode;
            t = newNode;
        }
    }
    Node* cur = h;
    bool a = true;
    while(cur != nullptr){
        if(a) cout << cur->data << " ";
        a = !a;
        cur = cur->next;
    }
}