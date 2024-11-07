#include <iostream>
#include <vector>

struct Node{

    int data { };
    Node* next { };
    Node* prev { };

    Node(){};

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


void deleteKey(Node*& head, int key){

    Node* currentNode { head };
    Node* prevNode { nullptr };

    while (currentNode){

        if (currentNode->data == key){

            if (currentNode == head){

                head = currentNode->next;
                currentNode = head;
                currentNode->prev = nullptr;
                continue;
            }

            if (currentNode->next == nullptr){
                prevNode->next = nullptr;
                currentNode = currentNode->next;
                continue;
            }

            prevNode->next = currentNode->next;
            currentNode->next->prev = prevNode;
            currentNode = currentNode->next;
        }

        else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        
    }
}

int main(){

    Node* head { nullptr };

    Node obj; 

    obj.insertAtEnd(11,  head);
    obj.insertAtEnd(8, head);
    obj.insertAtEnd(5, head);
    obj.insertAtEnd(1, head);
    obj.insertAtEnd(9, head);

    obj.traverse(head);

    deleteKey(head, 11);
    deleteKey(head, 1);
    deleteKey(head, 9);

    obj.traverse(head);

    return 0;
}