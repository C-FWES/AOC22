//
// Created by wou on 23/12/22.
//

#include <iostream>
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

    for (int i = 0; i < input.length()-4; ++i) {
        char a,b,c,d;
        a = input[i];
        b = input[i+1];
        c = input[i+2];
        d = input[i+3];
        if ((a != b and a != c and a != d) and (b != c and b != d)
        and (c != d)) {
            characterNum = i+3+1;
            break;
        }
    }

    cout << characterNum;

    return 0;
}