#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct User {
    string login;
    int balance;
};

bool cmp(const User& u1, const User& u2) {
    return u1.login < u2.login;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    vector<User> users(n);
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        getline(ss, users[i].login, ';');
        ss >> users[i].balance;
    }
    sort(users.begin(), users.end(), cmp);
    int m;
    string login,l;
    cin >> m;
    cin.ignore(); 
    getline(cin, login);
    for (int i1 = 0; i1 < m; i1++) {
        l = login.substr(0, 5);
        auto it = lower_bound(users.begin(), users.end(), User{l, 0}, cmp);
        if (it != users.end() && it->login == l) {
            cout << it->balance << " ";
            login.replace(0, 6, "");
        }
    }

    return 0;
}