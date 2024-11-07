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

void deleteDuplicate(Node*& head){

    int count { };

    Node* currentNode { head };
    Node* tempNode { nullptr };

    while (currentNode->next){

        if (currentNode->data == currentNode->next->data)
            count++;

        if (count > 0){
            tempNode = currentNode->next;
            currentNode->next = currentNode->next->next;
            count = 0;           
            delete tempNode;
        }
        else
            currentNode = currentNode->next;
    }
}


int main(){

    Node* head { nullptr };

    Node obj; 

    obj.insertAtEnd(1, head);
    obj.insertAtEnd(2, head);
    obj.insertAtEnd(3, head);
    obj.insertAtEnd(3, head);
    obj.insertAtEnd(5, head);

    obj.traverse(head);
    deleteDuplicate(head);
    obj.traverse(head);

    return 0;
}