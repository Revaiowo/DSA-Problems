#include <iostream>
#include <vector>
#include <string>

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

    void insertAtFront(int data, Node*& head){

        Node* temp { new Node(data, nullptr) };

        if (head == nullptr)
            head = temp;
        
        else {

            temp->next = head;
            head = temp;
        }
    }

    Node* insertatend(int data, Node*& head){

        Node* newNode { new Node(data, nullptr) };

        if (!head ) {
            head = newNode;
            return head;
        }

        Node* nextNode { head };

        while (nextNode->next) {

            nextNode = nextNode->next;
        }

        nextNode->next = newNode;

        return newNode;
   }
};

void addNumbers(Node* head1, Node* head2){

    Node* first { head1 };
    Node* second { head2 };
    Node* newHead { nullptr };
    Node obj;

    int sum { };
    int carry { };

    while (first || second || carry != 0){

        if (first){
            sum += first->data;
            first = first->next;
        }

        if (second){
            sum += second->data;
            second = second->next;
        }

        sum += carry;

        carry = sum / 10;
        sum = (sum > 9) ? (sum % 10) : sum;       

        obj.insertatend(sum, newHead);
        sum = 0;       
    }

    obj.traverse(newHead);
}

int main(){

    Node* head1 { nullptr };
    Node* head2 { nullptr };

    Node obj1;
    Node obj2;

    obj1.insertatend(2, head1);
    obj1.insertatend(8, head1);
    obj1.insertatend(9, head1);

    obj2.insertatend(5, head2);
    obj2.insertatend(2, head2);
    obj2.insertatend(4, head2);

    addNumbers(head1, head2);

    return 0;
}