#include <iostream>


struct Node{

    int data { };
    Node* next { };

    Node(){};

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

struct Queue{

    Node* front { nullptr };
    Node* rear { nullptr };

    bool isEmpty(){
        return rear == nullptr;
    }

    void enqueue(int data){

        if (isEmpty()){
            front = new Node(data);
            rear = front;
            return;
        }

        Node* newNode { new Node(data) };
        
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){

        if (isEmpty()){
            std::cout <<"Queue is empty" <<'\n';
            return;
        }

        if (front == rear)
            rear = nullptr;

        Node* tempNode { front };

        front = front->next;
        delete tempNode;
    }

    void traverse(){

        if (isEmpty()){
            std::cout <<"Queue is empty" <<'\n';
            return;
        }

        Node* currentNode { front };

        while (currentNode){
            std::cout <<currentNode->data <<' ';
            currentNode = currentNode->next;
        }
        
        std::cout <<'\n'; 
    }
};

int main(){

    Queue q;

    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(6);

    q.dequeue();
    q.dequeue();

    q.enqueue(9);
    q.enqueue(1);

    q.traverse();

    return 0;
}