#include <iostream>
#include <stack>
#include <string>

int convert(char ch){

    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else 
        return -1;
}

std::string infix_to_postfix(std::string& exp){

    std::string postExp;
    std::stack<char> s;

    for (char& ch : exp){


        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            postExp += ch;

        else if (ch == '(')
            s.push(ch);
        
        else if (ch == ')'){

            while (s.top() != '('){
                postExp += s.top();
                s.pop();
            }
            s.pop();
        }

        else {

            while (!s.empty() && convert(ch) <= convert(s.top())){
                postExp += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()){
        postExp += s.top();
        s.pop();
    }

    return postExp;
}

int main(){

    std::string exp { "a+b*(c^d-e)^(f+g*h)-i" };

    std::string postExp { infix_to_postfix(exp) };

    std::cout <<postExp;

    return 0;
}