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

std::vector<int> findPair(Node*& head, int target){

    Node* currentNode { head };
    std::vector<int> result { };

    while (currentNode->next){
        currentNode = currentNode->next;
    }

    Node* first { head };
    Node* last { currentNode };

    while (first->data < last->data ){

        int sum { first->data + last->data };

        if (sum > target){
            last = last->prev;
        }

        else if (sum < target)
           first = first->next;
        
        else {
            result.push_back(first->data);
            result.push_back(last->data);
            first = first->next;
            last = last->prev;
        }
    }

    return result;
}

int main(){

    Node* head { nullptr };

    Node obj; 

    int target { 10 };

    obj.insertAtEnd(1, head);
    obj.insertAtEnd(2, head);
    obj.insertAtEnd(4, head);
    obj.insertAtEnd(5, head);
    obj.insertAtEnd(6, head);
    obj.insertAtEnd(8, head);
    obj.insertAtEnd(9, head);

    std::vector<int> result { findPair(head, target) };

    for (auto& i : result)
        std::cout <<i <<' ';

    return 0;
}