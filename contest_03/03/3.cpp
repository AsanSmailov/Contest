#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int priority(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

vector<string> to_postfix(const string& infix) {
    stack<char> ops;
    vector<string> postfix;
    string str;
    for (char ch : infix) {
        if (isdigit(ch)) {
            str+=ch;
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix.push_back(str);
                str="";
                str = ops.top();
                ops.pop();
            }
            if (!ops.empty() && ops.top() == '(') {
                ops.pop();            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'
                   || ch == '^') {
            postfix.push_back(str);
            str="";
            while (!ops.empty() && priority(ch) <= priority(ops.top())&&priority(ch)!=3) {
                str = ops.top();
                postfix.push_back(str);
                str="";
                ops.pop();
            }
            ops.push(ch);
        }
    }
    while (!ops.empty()) {
        postfix.push_back(str);
        str="";
        str = ops.top();
        ops.pop();
    }
    postfix.push_back(str);
    return postfix;
}

int main() {
    string infix;
    cin>>infix;
    vector <string> postfix {to_postfix(infix)};
    for(int i=0; i<postfix.size();i++)
    cout << postfix[i]<<" "; 
    return 0;
}