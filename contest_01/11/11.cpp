#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c;
    d=abs(a-b);
    e=abs(a-c);
    if (d>e){
        cout<<"C "<<e;
    } else {
        cout<<"B "<<d;
    }

    return 0;
}