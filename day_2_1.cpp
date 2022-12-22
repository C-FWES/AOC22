//
// Created by wou on 21/12/22.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main () {
    map<string, string> winConditions {{"A", "Z"}, {"B", "X"}, {"C", "Y"},
            {"X", "C"}, {"Y", "A"}, {"Z", "B"}};
    map<string, int> shapeValues {{"X", 1}, {"Y", 2}, {"Z", 3}};
    vector<string> strategies;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        strategies.push_back(line);
    }
    int score = 0;
    for (int i = 0; i< strategies.size(); i+=1) {
        string strategy = strategies[i];
        string oppMove = strategy.substr(0, 1);
        string yourMove = strategy.substr(2, strategy.size());
        score += shapeValues[yourMove];
        if (oppMove == winConditions[yourMove]) {
            score += 6;
        }
        else if (yourMove == winConditions[oppMove]) {
            continue;
        }
        else {
            score += 3;
        }
    }
    cout << score;
    return 0;
}
