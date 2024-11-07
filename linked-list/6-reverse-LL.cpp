#include <iostream>
#include <vector>

struct Node{

    int data { };
    Node* next { };
    Node* prev { };

    Node(){}

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    void traverse(Node*& head){

        if (!head){
            std::cout <<"Empty LL";
            return;
        }
        
        Node* nextNode { head };

        while (nextNode) {

            std::cout <<nextNode->data <<' ';
            nextNode = nextNode->next;
        }
        std::cout <<'\n';

        delete nextNode;
    }

    void insertAtEnd(int data, Node*& head){

        Node* newNode { new Node(data, nullptr) };

        if (!head ) {
            head = newNode;
            return;
        }

        Node* nextNode { head };

        while (nextNode->next) {

            nextNode = nextNode->next;
        }

        nextNode->next = newNode;
    }
};

void reverseLL(Node*& head){

    Node* prevNode { nullptr };
    Node* currentNode { head };
    Node* nextNode { head };

    while (nextNode){

        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    head = prevNode;

    delete currentNode;
    delete nextNode;
}

int main(){

    Node* head { nullptr };

    Node obj;

    obj.insertAtEnd(4, head);
    obj.insertAtEnd(8, head);
    obj.insertAtEnd(5, head);

    obj.traverse(head);

    reverseLL(head);

    obj.traverse(head);

    return 0;
}
