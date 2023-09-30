#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a,b,c;
    cin>>a>>b;
    c=a/(b*b);
    cout<<setprecision(16)<<c;

    return 0;
}