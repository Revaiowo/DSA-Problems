#include <iostream>
#include <vector>
#include <algorithm>

struct Node{

    int data { };
    Node* next { };
    Node* prev { };

    Node(){}

    Node(int data, Node* prev, Node* next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    void traverse(Node*& head){

        if (head == nullptr){
            std::cout <<"Empty LL";
            return;
        }
        
        Node* nextNode { head };

        std::cout <<'\n';

        while (nextNode != nullptr) {

            std::cout <<nextNode->data <<' ';
            nextNode = nextNode->next;
        }

        std::cout <<'\n';
    }

    void insertAtEnd(int data, Node*& head){

        Node* newNode { new Node(data, nullptr, nullptr) };

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* nextNode { head };

        while (nextNode->next != nullptr){

            nextNode = nextNode->next;
        }

        nextNode->next = newNode;
        newNode->prev = nextNode;
    }
};

void reverseDLL(Node*& head){

    Node* currentNode { head };

    while (currentNode){

        head = currentNode;
        std::swap(currentNode->prev, currentNode->next);
        currentNode = currentNode->prev;
    }
}

int main(){

    Node* head { nullptr };

    Node obj;

    obj.insertAtEnd(5, head);
    obj.insertAtEnd(8, head);
    obj.insertAtEnd(4, head);
    obj.insertAtEnd(0, head);
    obj.insertAtEnd(7, head);

    obj.traverse(head);

    reverseDLL(head);

    obj.traverse(head);

    return 0;
}