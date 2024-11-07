#include <iostream>
#include <stack>

struct Queue{

    std::stack<int> s1;
    std::stack<int> s2;

    bool isEmpty(){
        return s1.empty() && s2.empty();
    }

    void enqueue(int data){

        if (isEmpty()){
            s1.push(data);
            return;
        }

        while (!s1.empty()){

            s2.push(s1.top());
            s1.pop();
        }

        s2.push(data);

        while(!s2.empty()){

            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue(){

        if (isEmpty()){
            std::cout <<"Queue is empty" <<'\n';
            return;
        }

        s1.pop();
    }

    void traverse(){

        while(!s1.empty()){

            std::cout <<s1.top() <<' ';
            s2.push(s1.top());
            s1.pop();
        }

        std::cout <<'\n';

        while(!s2.empty()){

            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main(){

    Queue q;

    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(0);

    q.traverse();

    q.dequeue();
    q.dequeue();
    q.enqueue(8);
    q.enqueue(33);
    
    q.traverse();

    return 0;
}