#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,q,f=0,s=0;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    vector <int> b(m);
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    vector <int> c;
    q=n+m;
    for(int i=0;i<q;i++){
        if(f>=n){ 
            c.push_back(b[s]);
            s++;
        }else if(s>=m){ 
            c.push_back(a[f]);
            f++;
        }else if(a[f]<b[s]){
            c.push_back(a[f]);
            f++;
        }else {
            c.push_back(b[s]);
            s++;
        }
    }
    for (int i:c){
        cout<<i<<" ";
    }
    

    return 0;
}
