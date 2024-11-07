#include <iostream>


struct Queue{

    int front { -1 };
    int rear { -1 };
    static const int MAX_SIZE { 1000 };
    int arr[MAX_SIZE];

    bool isEmpty(){
        return rear == -1;
    }

    bool isFull(){
        return rear == MAX_SIZE-1;
    }

    void enqueue(int data){

        if (isFull()){
            std::cout <<"The queue is full" <<'\n';
            return;
        }

        if (isEmpty())
            front = 0;
        
        arr[++rear] = data;
    }

    void dequeue(){

        if (isEmpty()){
            std::cout <<"The queue is empty" <<'\n';
            return;
        }

        if (front == rear & front != -1){
            front = rear = -1;
            return;
        }

        front++;
    }

    void traverse(){

        if (isEmpty()){
            std::cout <<"The queue is empty" <<'\n';
            return;
        }

        for (int i=front; i<=rear; i++)
            std::cout <<arr[i] <<' ';
        
        std::cout <<'\n';
    }
};

int main(){

    Queue q;

    q.enqueue(3);  
    q.enqueue(7);  
    q.enqueue(4);  
    q.enqueue(9);

    q.traverse();

    q.dequeue();
    q.dequeue();

    q.enqueue(0);
    q.enqueue(1);

    q.traverse();

    return 0;
}