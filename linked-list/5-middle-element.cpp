#include <iostream>
#include <vector>

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

int middleElement(Node*& head){

    int ans { };

    Node* slowNode { head };
    Node* fastNode { head };

    while (fastNode && fastNode->next){

        slowNode = slowNode->next;
        ans = slowNode->data;
        fastNode = fastNode->next->next;
    }

    return ans;
}

int main(){

    Node* head { nullptr };

    Node obj;

    obj.insertAtEnd(5, head);
    obj.insertAtEnd(9, head);
    obj.insertAtEnd(2, head);
    obj.insertAtEnd(6, head);
    obj.insertAtEnd(1, head);
    obj.insertAtEnd(8, head);

    obj.traverse(head);

    int result { middleElement(head) };

    std::cout <<result; 

    return 0;
}