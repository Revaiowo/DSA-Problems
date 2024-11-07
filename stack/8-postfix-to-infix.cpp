#include <iostream>
#include <stack>
#include <string>

std::string postfix_to_infix(std::string& exp){

    std::stack<std::string> s;
    std::string ch { };

    std::string top1 { };
    std::string top2 { };

    for (int i=0; i<exp.size(); i++){

        ch = exp[i];

        if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
            s.push(ch);
        
        else {
            top1 = s.top();
            s.pop();
            top2 = s.top();
            s.pop();

            s.push(top2 + ch + top1);
        }
    }

    return s.top();
}

int main(){

    std::string exp { "pqm*+x-" };

    std::string infixExp { postfix_to_infix(exp) };

    std::cout <<infixExp <<'\n';

    return 0;
}