#include <iostream>
#include <stack>

struct MinStack{

    std::stack<std::pair<int,int>> minStack;
    int min { INT_MAX };

    bool isEmpty(){
        return minStack.empty();
    }

    void push(int data){

        min = std::min(min, data);
        minStack.push( {data, min} );
    }

    void pop(){

        if (isEmpty()){
            std::cout <<"Stack is empty." <<'\n';
            return;
        }

        minStack.pop();
    }

    void getMin(){

        if (isEmpty()){
            std::cout <<"Stack is empty." <<'\n';
            return;
        }

        std::pair<int,int> pair { minStack.top() };

        std::cout <<pair.second <<'\n';
    }
};

int main(){

    MinStack s;

    s.push(5);
    s.push(8);
    s.push(4);
    s.push(1);
    s.push(9);

    s.getMin();

    return 0;
}
