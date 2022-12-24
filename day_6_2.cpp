//
// Created by wou on 23/12/22.
//

#include <iostream>
#include <set>

using namespace std;

int main () {
    string input;
    string line;
    while (getline(cin, line)) {
        if (line == "stop") {
            break;
        }
        input = line;
    }

    int characterNum = 0;

    set<char> seen;

    for (int i = 0; i < input.length() - 14; ++i) {
        int count = 0;
        string currSection = input.substr(i, 14);
        for (int k = 0; k < currSection.length(); ++k) {
            if (seen.count(currSection[k])) {
                break;
            }
            seen.insert(currSection[k]);
            ++count;
        }
        seen.clear();
        if (count == currSection.length()) {
            characterNum = int(i + currSection.length()); break;}
    }

    cout << characterNum;

    return 0;
}