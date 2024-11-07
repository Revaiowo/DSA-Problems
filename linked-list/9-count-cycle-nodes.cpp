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

        if (count == 5)
            newNode->next = head->next;
    }
};

int countCycleNodes(Node*& head){

    // Using tortoise and hare algorithm 

    int count { 1 };

    Node* hare { head };
    Node* tortoise { head };

    while (hare && hare->next){

        tortoise= tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare){

            tortoise = tortoise->next;

            while (tortoise != hare){
                count++;
                tortoise = tortoise->next;
            }     

            return count;
        }

    }

    return -1;
}

int main(){

    Node* head { nullptr };
    int count { };

    Node obj;

    obj.insertAtEnd(3, head, count);
    obj.insertAtEnd(8, head, count);
    obj.insertAtEnd(2, head, count);
    obj.insertAtEnd(9, head, count);
    obj.insertAtEnd(1, head, count);

    int result { countCycleNodes(head) };

    std::cout <<result;

    return 0;
}