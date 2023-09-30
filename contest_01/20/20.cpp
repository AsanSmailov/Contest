#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    sort(num1.begin(), num1.end()); // сортируем цифры первого числа
    sort(num2.begin(), num2.end()); // сортируем цифры второго числа

    if (num1 == num2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
} 