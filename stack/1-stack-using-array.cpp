#include <iostream>
#include <vector>

struct Stack{

    int top { -1 };
    static const int MAX_SIZE { 1000 };
    int arr[MAX_SIZE];

    bool isEmpty(){

        return top == -1;
    }

    void getTop(){

        if (isEmpty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        std::cout <<"Top: " <<arr[top] <<'\n';
    }

    void push(int data){

        if (top == MAX_SIZE-1){
            std::cout <<"The stack is full" <<'\n';
            return;
        }

        arr[++top] = data;
    }

    void pop(){

        if (isEmpty()){
            std::cout <<"The stack is empty" <<'\n';
            return;
        }

        top--;
    }

    void traverse(){

        if (isEmpty()){
            std::cout <<"The stack is empty" <<'\n';
            return;
        }

        for (int i=0; i<=top; i++)
            std::cout <<arr[i] <<' ';
    }
};

int main(){

    Stack s;

    s.push(1);
    s.push(4);
    s.push(8);
    s.push(6);

    s.pop();
    s.pop();

    s.push(2);
    s.getTop();

    s.traverse();

    return 0;
}