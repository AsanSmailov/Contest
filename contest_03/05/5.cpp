#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> freq;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        freq[word]++;
    }

    int max_freq = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        max_freq = max(max_freq, it->second);
    }

    vector<string> most_freq_words;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second == max_freq) {
            most_freq_words.push_back(it->first);
        }
    }

    sort(most_freq_words.begin(), most_freq_words.end());

    for (string w : most_freq_words) {
        cout << w << " ";
    }

    return 0;
}