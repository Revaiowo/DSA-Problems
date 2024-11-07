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

std::string prefix_to_infix(std::string& exp){

    std::stack<std::string> s;
    std::string ch { };

    std::string top1 { };
    std::string top2 { };

    for (int i=exp.size()-1; i>=0; i--){

        ch = exp[i];

        if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
            s.push(ch);
        
        else {
            top1 = s.top();
            s.pop();
            top2 = s.top();
            s.pop();

            s.push(top1 + ch + top2);
        }
    }

    return s.top();
}


std::string prefix_to_postfix(std::string& exp){

    exp = prefix_to_infix(exp);

    exp = infix_to_postfix(exp);

    return exp;
}

int main(){

    std::string exp { "++x/*yzwa" };

    std::string postfixExp { prefix_to_postfix(exp) };

    std::cout <<postfixExp <<'\n';

    return 0;
}