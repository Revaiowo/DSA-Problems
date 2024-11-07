#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

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

std::string infix_to_prefix(std::string& exp){

    std::string preExp;
    std::stack<char> s;
    char ch { };

    for (int i = exp.size()-1; i>=0; i--){

        ch = exp[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            preExp += ch;

        else if (ch == ')')
            s.push(ch);
        
        else if (ch == '('){

            while (s.top() != ')'){
                preExp += s.top();
                s.pop();
            }
            s.pop();
        }

        else if (ch == '^'){

            while (!s.empty() && convert(ch) < convert(s.top())){
                preExp += s.top();
                s.pop();
            }
            s.push(ch);
        }

        else {

            while (!s.empty() && convert(ch) < convert(s.top())){
                preExp += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()){
        preExp += s.top();
        s.pop();
    }

    std::reverse(preExp.begin(), preExp.end());

    return preExp;
}

int main(){

    std::string exp { "x+y^z/y*a" };

    std::string preExp { infix_to_prefix(exp) };

    std::cout <<preExp;

    return 0;
}