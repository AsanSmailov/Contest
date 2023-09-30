#include <iostream>

using namespace std;

int main() {
    int n,a,s;
    cin >> n;
    a=2;

    int width = 1; 
    int count = 1; 
    bool increasing = true; 
    while (count <= n) {
        if (increasing==true) {
            for (int i = 0; i < width && count <= n; i++) {
            cout << count << " ";
            count++;
            }
            cout << endl;
            if (width == a) increasing = false; 
            width++;
        } else {
            width--;
            for (s=1; s < width && count <= n; s++) {
            cout << count << " ";
            count++;
            }
            cout << endl;
            if (width==2) {a++;
            width=2;
            if (width != a) increasing = true;
            }
        }
    }

    return 0;
}