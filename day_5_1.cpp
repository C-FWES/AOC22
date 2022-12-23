//
// Created by wou on 22/12/22.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main () {
    map<string, vector<char>> stacks;
    vector<vector<int>> moves;
    string line;
    int length = 0;
    int numOfColumns = 0;
    bool checkedColumnNumber = false;

    while (getline(cin, line)) {
        if (line == "stop") {break;}

        if (line.find("move") != string::npos and line.find("from") != string::npos) {
            //parse move line
            int foundInt;
            string temp;
            vector<int> steps;
            stringstream str(line);
            while (str.good()) {
                str >> temp;
                if (stringstream(temp) >> foundInt) {
                    steps.push_back(foundInt);
                }
            }
            moves.push_back(steps);
        }

        else if (line.empty()) {
            continue;
        }
        else {
            if (not checkedColumnNumber) {
                numOfColumns = (int)line.length()/4+1; checkedColumnNumber = true;
            }
            int countFourJumps = 0;

            for (int i = 1; i < line.length()-1; i+=4) {
                ++countFourJumps;
                if (isdigit(line[i])) {break;} //the last line of numbers that we don't care about
                if (isalpha(line[i])) {
                    int columnNum = countFourJumps;
                    stacks[to_string(columnNum)].push_back(line[i]);
                }
            }
        }
    }

    for (auto moveSet : moves) {
        int howManyToMove = moveSet[0];
        int from = moveSet[1];
        int to = moveSet[2];
        vector<char> fromSet = stacks[to_string(from)];
        vector<char> moveTo;
        for (int m = 0; m < howManyToMove; ++m) {
            moveTo.push_back(fromSet[m]);
            stacks[to_string(from)].erase(stacks[to_string(from)].begin());
        }
        std::reverse(moveTo.begin(), moveTo.end());
        stacks[to_string(to)].insert(begin(stacks[to_string(to)]), begin(moveTo), end(moveTo));
    }

    string finalMessage;

    for (int k = 0; k < numOfColumns; ++k) {
        vector<char> currStack = stacks[to_string(k+1)];
        char firstChar = currStack[0];
        finalMessage += firstChar;
    }

    cout << finalMessage;

    return 0;
}