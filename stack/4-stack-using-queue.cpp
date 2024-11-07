#include <iostream>
#include <queue>

struct Stack{

    std::queue<int> q;

    bool isEmpty(){
        return q.empty();
    }

    void push(int data){

        q.push(data);

        for(int i=0; i<q.size()-1; i++){
            
            int temp { q.front() };
            q.pop();
            q.push(temp);
        }
    }  

    void pop(){

        if (q.empty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        q.pop();
    }

    void top(){

        if (q.empty()){
            std::cout <<"Stack is empty" <<'\n';
            return;
        }

        std::cout <<"Top: " <<q.front() <<'\n';
    }

    void traverse(){

        while (!q.empty()) {
            std::cout << q.front() << " ";
            q.pop();
        }
        std::cout <<'\n';
    }

    int size(){
        return q.size();
    }

    int front(){
        return q.front();
    }
    
};

int main(){

    Stack s;

    s.push(5);
    s.push(8);
    s.push(7);
    s.push(2);

    s.pop();

    s.push(9);

    s.traverse();

    return 0;
}