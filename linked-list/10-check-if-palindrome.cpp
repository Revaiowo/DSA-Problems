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

    void insertAtEnd(int data, Node*& head, int& count){

        Node* newNode { new Node(data, nullptr) };
        count++;

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

Node* reverseLL(Node*& head){

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

    return head;
}

bool checkPalindrome(Node*& head){

    // will reverse only half of the linked list also get the hlaf way point using slow and fast pointers

    Node* slow { head };
    Node* fast { head };

    while (fast->next && fast->next->next){

        slow = slow->next;
        fast= fast->next->next;
    }

    Node* temp { slow->next };
    Node* newHead { reverseLL(temp) };

    Node* first { head };
    Node* second = newHead;

    while (second) {

        if (first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        
        first = first->next;
        second = second->next;
    }

    delete first;
    delete second;

    reverseLL(newHead);

    return true;
}

int main(){

    Node* head { nullptr };
    int count { };

    Node obj;

    obj.insertAtEnd(4, head, count);
    obj.insertAtEnd(1, head, count);
    obj.insertAtEnd(9, head, count);
    obj.insertAtEnd(9, head, count);
    obj.insertAtEnd(2, head, count);
    obj.insertAtEnd(4, head, count);

    bool result { checkPalindrome(head) };

    std::cout <<std::boolalpha;
    std::cout <<result <<'\n';

    obj.traverse(head);

    return 0;
}