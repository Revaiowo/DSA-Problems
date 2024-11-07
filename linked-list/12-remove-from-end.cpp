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

void reverseFromEnd(Node*& head, int position){

    Node* slow { head };
    Node* fast { head };

    for (int i=1; i<position; i++)
        fast = fast->next;

    // this is when the head node is to be deleted, meaning the position is lenght of LL
    if (!(fast->next)){

        head = head->next;
        return;
    }

    while (fast->next->next){

        fast = fast->next;
        slow = slow->next;
    }

        
    delete slow->next;

    slow->next = slow->next->next;
}

int main(){

    Node* head { nullptr };

    Node obj;

    obj.insertatend(4, head);
    obj.insertatend(0, head);
    obj.insertatend(9, head);
    obj.insertatend(2, head);
    obj.insertatend(7, head);

    obj.traverse(head);
    reverseFromEnd(head, 5);
    obj.traverse(head);

    return 0;
}