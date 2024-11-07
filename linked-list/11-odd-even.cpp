#include <iostream>
#include <vector>

struct node{

    int data { };
    node* next { };
    node* prev { };

    node(){}

    node(int data, node* next){
        this->data = data;
        this->next = next;
    }

    void traverse(node*& head){

        if (!head){
            std::cout <<"empty ll";
            return;
        }
        
        node* nextnode { head };

        while (nextnode) {

            std::cout <<nextnode->data <<' ';
            nextnode = nextnode->next;
        }
        std::cout <<'\n';

        delete nextnode;
    }

    void insertatend(int data, node*& head, int& count){

        node* newnode { new node(data, nullptr) };
        count++;

        if (!head ) {
            head = newnode;
            return;
        }

        node* nextnode { head };

        while (nextnode->next) {

            nextnode = nextnode->next;
        }

        nextnode->next = newnode;
   }
};
void evenodd(node*& head){

    int count { 1 };

    node* prevnode { nullptr };
    node* currentnode { head };
    node* nextnode { head };
    node* firstevennode { head->next };

    while (nextnode->next) {

        count++;

        prevnode = currentnode;
        nextnode = nextnode->next;
        currentnode->next = currentnode->next->next;
        currentnode = nextnode; 
    }

    if (count % 2 == 0)
        currentnode->next = head;
    else
        prevnode->next = head;

    head = firstevennode;
}


void oddeven(node*& head){

    // odd then even 

    int count { 1 };

    node* prevnode { nullptr };
    node* currentnode { head };
    node* nextnode { head };
    node* firstevennode { head->next };

    while (nextnode->next) {

        count++;

        prevnode = currentnode;
        nextnode = nextnode->next;
        currentnode->next = currentnode->next->next;
        currentnode = nextnode; 
    }

    if (count % 2 == 0)
        prevnode->next = firstevennode;
    else
        currentnode->next = firstevennode;
}

int main(){

    node* head { nullptr };
    int count { };

    node obj;

    obj.insertatend(4, head, count);
    obj.insertatend(0, head, count);
    obj.insertatend(9, head, count);
    obj.insertatend(2, head, count);
    obj.insertatend(7, head, count);

    obj.traverse(head);

    evenodd(head);

    obj.traverse(head);

    return 0;
}