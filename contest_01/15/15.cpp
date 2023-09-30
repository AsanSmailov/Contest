#include <iostream>
#include <string>
using namespace std;

 
int main()
{
    string str;
    cin>>str;
    string e;
    int c;
 
    for (int i = 0; str[i]; i++)
    {
        c = 1;
        while (str[i] == str[i + 1]) {
            c++, i++;
        }
        if (c>1){
        e += str[i] + to_string(c);
        } else {
            e += str[i];
        }
    }

 
    cout << e;
 
    return 0;
}