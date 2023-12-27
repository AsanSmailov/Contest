#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isBalanced(vector<char> text) {
    stack<char> s;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            s.push(text[i]);
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (s.empty()) {
                return false;
            } else if ((text[i] == ')' && s.top() == '(') ||
                       (text[i] == ']' && s.top() == '[') ||
                       (text[i] == '}' && s.top() == '{')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    vector<char> a;
    int s = 1, d = -1;
    for (int i = 0; d == -1; i++) {
        char c;
        cin >> c;
        if (c == '!') {
            d = i;
        }
        else {
            a.push_back(c);
        }
    }
    if (isBalanced(a)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
} 

