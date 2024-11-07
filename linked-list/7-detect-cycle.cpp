#include <iostream>
#include <vector>
#include <unordered_map>

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

bool detectCycle(Node*& head){

    bool cycle { false };

    // Using tortoise and hare algorithm 

    Node* hare { head };
    Node* tortoise { head };

    while (hare && hare->next){

        tortoise= tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare){
            cycle = true;
            break;       
        }
    }

    // Using Hashmaps
    std::unordered_map<Node*, int> hashList { };
    Node* currentNode { head };

    while (currentNode){

        hashList[currentNode] = 1;      
        auto it { hashList.find(currentNode->next) };
        if (it != hashList.end() ){
            cycle = true;
            break;
        } 
        currentNode = currentNode->next;
    }

    return cycle;
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

    bool result { detectCycle(head) };

    std::cout <<std::boolalpha;
    std::cout <<result;

    return 0;
}