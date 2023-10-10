#include "fstream"
#include "iostream"
#include "vector"
#include <iterator>
#include <string>

using namespace std;

int main() {
    ifstream file("data.txt"); 
    string word,d;
    int j=0;
    while(word!="stopword"){
        file >> word;
        cout<< word;
        j++;
    }
    //vector<string> vec(j);
    int a=0;
    while(word!="stopword"){
        file >> d;
        cout << d;
        //vec[a]=word;
        a++;
    }

}