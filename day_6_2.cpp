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


    for (int i = 0; i < input.length() - 14; ++i) {
        set<char> seen;
        for (int k = i; k < i + 14; ++k) {
            if (seen.count(input[k])) {
                break;
            }
            seen.insert(input[k]);

        }
        if (seen.size() == 14) {
            characterNum = int(i + 14); break;}
    }

    cout << characterNum;

    return 0;
}
