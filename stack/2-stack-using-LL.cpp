#include <iostream>

struct Node{

    int data { };
    Node* next { nullptr };

    Node(){};

    Node(int data){
        this->data = data;
    }
};

struct Stack{
    
    Node* top { nullptr };

    bool isEmpty(){
        return top == nullptr;
    }

    void push(int data){

        if (isEmpty()){
            top = new Node(data);
            return;
        }

        Node* newNode { new Node(data) };

        newNode->next = top;
        top = newNode;
    }

    void pop(){

        if (isEmpty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        Node* tempNode { top };
        top = top->next;

        delete tempNode;
    }

    void Top(){

        if (isEmpty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        std::cout <<top->data <<'\n';
    }

    void traverse(){

        if (isEmpty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        // not that the traversal will be in reverse

        Node* currentNode { top };

        while (currentNode){
            std::cout <<currentNode->data <<' ';
            currentNode = currentNode->next;
        }

        std::cout <<'\n';
    }

};

int main(){

    Stack s;

    s.pop();

    s.push(5);
    s.push(4);
    s.push(8);
    s.push(6);

    s.traverse();

    s.pop();
    s.pop();

    s.push(1);
    s.push(0);

    s.traverse();

    s.Top();

    return 0;
}