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

void findIntersection(Node* head1, Node* head2){

    // Approach 1:

    Node* first { head1 };
    Node* second { head2 };

    while (first != second){

        first = first == nullptr ? head2 : first->next;
        second = second == nullptr ? head1 : second->next;

        if (first == second && first != nullptr){
            std::cout <<first->data;
            return;
        }
    }

    // Approach 2:

    // int size1 { 1 };
    // int size2 { 1 };

    // Node* first { head1 };
    // Node* second { head2 };

    // while (first->next || second->next){

    //     if (first->next){
    //         size1++;
    //         first = first->next;
    //     }

    //     if (second->next){
    //         size2++;
    //         second = second->next;
    //     }
    // }

    // first = head1;
    // second = head2;

    // int difference { };

    // if (size1 > size2)
    //     difference = size1 - size2;
    
    // else if (size1 < size2)
    //     difference = size2 - size1;


    // for (int i=1; i<=difference; i++){

    //     if (size1 > size2)
    //         first = first->next;
        
    //     else    
    //         second = second->next;
    // }

    // while (first){

    //     if (first == second){
    //         std::cout <<first->data;
    //         return;
    //     }

    //     first = first->next;
    //     second = second->next;
    // }
    
    std::cout <<"No intersaction found.";

}

int main(){

    Node* head1 { nullptr };
    Node* head2 { nullptr };

    Node obj1;
    Node obj2;

    obj1.insertatend(4, head1);
    Node* node1 = obj1.insertatend(8, head1);
    obj1.insertatend(0, head1);
    obj1.insertatend(9, head1);

    obj2.insertatend(1, head2);
    obj2.insertatend(8, head2);
    obj2.insertatend(3, head2);
    obj2.insertatend(7, head2);
    obj2.insertatend(0, head2);
    obj2.insertatend(5, head2);
    Node* node2 = obj2.insertatend(12, head2);

    node2->next = node1;

    obj1.traverse(head1);
    obj2.traverse(head2);

    findIntersection(head1, head2);

    return 0;
}