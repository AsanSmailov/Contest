#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int main() {
    int pclass;
    double age;
    cin >> pclass >> age;

    set<pair<int, string>> res;

    ifstream file("train.csv");
    file.ignore(100, '\r');
    string line;
    int i = 1;
    while (getline(file, line, '\r')) {
        stringstream ss(line);
        ss.ignore(10, ',').ignore(10, ',');

        int pclass_f;
        ss >> pclass_f;
        if (pclass_f != pclass) {
            continue;
        }
        string name;
        getline(ss.ignore(2), name, '"');
        while (ss.peek() == '"') {
            string temp;
            getline(ss.ignore(1), temp, '"');
            name += '"' + temp + '"';
            ss.ignore(1);

            getline(ss, temp, '"');
            name += temp;
        }
        ss.ignore(1);
        string sex;
        getline(ss, sex, ',');
        if (sex == "male") {
            continue;
        }
        int age_f;
        string age_fs;
        getline(ss, age_fs, ',');
        if (age_fs == "") {
            age_f = 0;
        }
        else {
            age_f = stoi(age_fs);
        }
        if (age_f <= age) {
            continue;
        }
        res.insert({ age_f, name });
    }

    for (auto& it : res) {
        cout << it.second << "\n";
    }
    return 0;
}