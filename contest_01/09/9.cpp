#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    double a,b,c;
    cin>>a;
    cin>>b;
    c=sqrt(a*a+b*b);
    cout<<setprecision(16)<<c;

    return 0;
}