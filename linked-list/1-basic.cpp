#include <iostream>
#include <vector>

struct Node {

    int data { };
    Node* next { };

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

void traverse(Node*& head){

    if (head == nullptr)
        std::cout <<"Empty LL";
    
    Node* nextNode { head };

    while (nextNode) {

        std::cout <<nextNode->data <<' ';
        nextNode = nextNode->next;
    }

    std::cout <<'\n';
}

void insertAtEnd(int data, Node*& head){

    if (head == nullptr){
        Node* temp { new Node(data, nullptr) };
        head = temp;
    }

    else {

        Node* temp { new Node(data, nullptr) };

        Node* nextNode { head };

        while (nextNode->next != nullptr) {

            nextNode = nextNode->next;
        }

        nextNode->next = temp;
    }
}

void insertAtFront(int data, Node*& head){

    Node* temp { new Node(data, nullptr) };

    if (head == nullptr)
        head = temp;
    
    else {

        temp->next = head;
        head = temp;
    }
}

void deleteNode(int position, Node*& head){

    if (position == 1){
        head = head->next;
        return;
    }

    Node* nextNode { head };
    Node* prevNode { nullptr };

    for (int i=1; i<position; i++){

        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    prevNode->next = nextNode->next;
}

void insertAtK(int data, int position, Node*& head){

    Node* newNode { new Node(data, nullptr) };

    if (position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* prevNode { nullptr };
    Node* nextNode { head };

    for (int i=1; i<position; i++){

        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    if (!nextNode){
        prevNode->next = newNode;
        return;
    }

    prevNode->next = newNode;
    newNode->next = nextNode;
}

int main(){

    Node* head { nullptr };

    insertAtEnd(5, head);
    insertAtEnd(3, head);
    insertAtEnd(9, head);
    insertAtEnd(1, head);

    // insertAtFront(100, head);
    // insertAtFront(50, head);
    // insertAtFront(69, head);

    // traverse(head);

    // deleteNode(5, head);
    // deleteNode(8, head);
    // deleteNode(1, head);

    traverse(head);
    
    insertAtK(15, 3, head);
    insertAtK(100, 6, head);
    insertAtK(0, 1, head);

    traverse(head);

    return 0;
}