#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long int n,d,res;
    res=0;
    cin>>n;
    std::vector<long int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int left = 0, right = n - 1;
    long int  level = 0;

    while (left < right) {
        if (a[left] < a[right]) {
            level = max(level, a[left]);
            res += level - a[left];
            left++;
        } else {
            level = max(level, a[right]);
            res += level - a[right];
            right--;
        }
    }
    cout<<res;

    return 0;
}