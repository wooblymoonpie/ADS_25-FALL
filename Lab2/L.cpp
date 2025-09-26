#include <iostream>
#include <deque>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int maxsum(Node* head){
    if (!head) return 0;

    int max_sum = head->data;  //maxim
    int cur_sum = head->data;  //current

    Node* cur = head->next;
    while(cur){
        cur_sum = max(cur->data, cur_sum + cur->data);  
        max_sum = max(max_sum, cur_sum);                
        cur = cur->next; 
    }
    return max_sum;
}

int main(){
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;


    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        Node* newNode = new Node(x);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }
    cout << maxsum(head) << endl;
    return 0;
}