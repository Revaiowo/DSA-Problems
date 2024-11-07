#include <iostream>
#include <vector>

struct Node{

    int data { };
    Node* next { };
    Node* prev { };

    Node(int data, Node* prev, Node* next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

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

void insertAtFront(int data, Node*& head){

    Node* newNode { new Node(data, nullptr, nullptr) };

    newNode->next = head;
    head = newNode;
}

void insert(int data, int position, Node*& head){

    Node* newNode { new Node(data, nullptr, nullptr) };

    if (head == nullptr){
        head = newNode;
        return;
    }

    // When adding in front
    if (position == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* prevNode { nullptr };
    Node* nextNode { head };

    for (int i=1; i<position; i++){

        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    // When adding at last
    if (!nextNode){
        std::cout <<1<<' ';

        prevNode->next = newNode;
        newNode->prev = prevNode;
        return;
    }

    // when adding in middle
    prevNode->next = newNode;

    newNode->prev = prevNode;
    newNode->next = nextNode;

    nextNode->prev = newNode;
}

void deleteNode(int position, Node*& head){

    if (position == 1 && head->next == nullptr){
        head = nullptr;
        return;
    }
    
    if (position == 1){
        Node* temp { head->next };
        temp->prev = nullptr;
        head = temp;
        return;
    }

    Node* prevNode { nullptr };
    Node* nextNode { head };

    for (int i=1; i<position; i++){

        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    if (nextNode->next == nullptr){

        prevNode->next = nullptr;
        return;
    }

    prevNode->next = nextNode->next;
    nextNode->next->prev = prevNode;
}

int main(){

    Node* head { nullptr };

    insertAtEnd(11,  head);
    insertAtEnd(8, head);
    insert(4, 3, head);
    // insert(9, 4, head);
    // insert(5, 5, head);
    // insert(100, 3, head);

    traverse(head);

    // deleteNode(6, head);

    // traverse(head);

    return 0;
}