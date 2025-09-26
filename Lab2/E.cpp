#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Stack{
public:
    Node<T> *topNode;
    int sz;
public:
    Stack(){
        topNode = NULL;
        sz = 0;
    }

    void push(T data){
        Node<T> *node = new Node<T>(data);
        node->next = topNode;
        topNode = node;
        sz++;
    }

    void pop(){
        if (topNode != NULL){
            Node<T> *tmp = topNode;
            topNode = topNode->next;
            delete tmp;
            sz--;
        }
    }

    int size() const{
        return sz;
    }

    bool empty() const{
        return (sz == 0);
    }

    T top() const{
        return topNode->data;
    }
};

int main(){
    Stack<string> st; 

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        if(st.empty()){
            st.push(name);
        } else if (st.top() != name){
            st.push(name);
        }
    }
    cout << "All in all: " << st.size() << endl;
    cout << "Students:" << endl;
    int size = st.size();

    for(int i = 0; i < size; i++){
        cout << st.top() << endl;
        st.pop();
    }
}