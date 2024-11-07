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

int searchElement(int target, Node*& head){

    Node* nextNode { head };

    for (int i=1; nextNode != nullptr; i++){

        if (nextNode->data == target)
            return i;
        
        nextNode = nextNode->next;
    }

    return -1;
}

int main(){

    Node* head { nullptr };
    int target { 4 };

    insertAtEnd(4, head);
    insertAtEnd(2, head);
    insertAtEnd(6, head);
    insertAtEnd(9, head);

    int result { searchElement(target, head) };

    std::cout <<std::boolalpha;
    std::cout <<result;

    return 0;
}