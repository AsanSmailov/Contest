#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int z, x;
    set<string> s;
    cin >> z;
    vector<string> a(z);
    for (int i = 0; i < z; i++) {
        cin >> a[i];
    }
    cin >> x;
    vector<string> b(x);
    for (int i = 0; i < x; i++) {
        cin >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(s, s.begin()));
    if (s.empty()) {
        cout << "-1";
    } else {
        for (const auto word : s) {
            cout << word << " ";
        }
    }
    return 0;
} 