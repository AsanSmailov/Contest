#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int print(vector <pair<string,int>> f){
    int max1=0,max2=0,max3=0;
    vector<string> v(3);
    for(auto element:f){
        if(element.second>max1){
            max1=element.second;
            v[2]=v[1];
            v[1]=v[0];
            v[0]=element.first;
        } else if(element.second>max2){
            max2=element.second;
            v[2]=v[1];
            v[1]=element.first;
        } else if(element.second>max3){
            max3=element.second;
            v[2]=element.first;
        } 
    }
    cout<<v[0]<<' '<<v[1]<<" "<<v[2];
    return 0;
}

int main() {
    ifstream file("data.txt"); 
    string word,d,s;
    int j=0;
    while(word!="stopword"){
        file >> word;
        j++;
    }
    file.close();
    vector<string> vec(j);
    int a=0;
    file.open("data.txt");
    while(d!="stopword"){
        file >> d;
        vec[a]=d;
        a++;
    }
    cin>>s;
    map<string,int> f;
    string w;
    for(int i=0;i<j;i++){
        if(vec[i]==s){
            w=vec[i+1];
            f[w]++;
        }
    }
    vector <pair<string,int>> v(f.begin(),f.end());
    print(v);
}
