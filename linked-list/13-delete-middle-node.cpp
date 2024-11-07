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
            std::cout <<"empty ll";
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

    void insertatend(int data, Node*& head){

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

void deleteMidddleNode(Node*& head){

    Node* slow { head };
    Node* fast { head };
    Node* prevNode { nullptr };

    while (fast && fast->next){

        prevNode = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prevNode->next = slow->next;
    delete slow;
}

int main(){

    Node* head { nullptr };

    Node obj;

    obj.insertatend(4, head);
    obj.insertatend(0, head);
    obj.insertatend(9, head);
    obj.insertatend(2, head);
    obj.insertatend(7, head);
    obj.insertatend(8, head);

    obj.traverse(head);
    deleteMidddleNode(head);
    obj.traverse(head);

    return 0;
}