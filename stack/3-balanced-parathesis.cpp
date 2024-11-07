#include <iostream>
#include <stack>
#include <string>

bool checkParanthesis(std::string& str){

    std::stack<char> s;

    for (char i : str){

        if (i == '(' || i == '{' || i == '[')
            s.push(i);
        
        else {
            if (i == ')' && s.top() == '('){
                s.pop();
            }
            else if (i == '}' && s.top() == '{'){
                s.pop();
            }
            else if (i == ']' && s.top() == '['){
                s.pop();
            }
            else
                return false;
        }
    }

    return s.empty();
}

int main(){

    std::string str { "(){(){}()}" }; 

    bool result { checkParanthesis(str) };

    std::cout <<result;

    return 0;
}