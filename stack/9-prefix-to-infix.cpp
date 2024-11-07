#include <iostream>
#include <stack>
#include <string>

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

int main(){

    std::string exp { "++x/*yzwa" };

    std::string infixExp { prefix_to_infix(exp) };

    std::cout <<infixExp <<'\n';

    return 0;
}