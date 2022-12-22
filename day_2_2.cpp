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
        //x - rock
        // y - paper
        // z - scissors
        if (yourMove == "X") {
            // you have to lose
            score += 0;
            if (oppMove == "A") {score += 3;}
            if (oppMove == "B") {score += 1;}
            if (oppMove == "C") {score += 2;}
        }
        else if (yourMove == "Y") {
            score += 3;
            // you have to draw
            if (oppMove == "A") {score += 1;}
            if (oppMove == "B") {score += 2;}
            if (oppMove == "C") {score += 3;}
        }
        else { //z
            // you have to win
            score += 6;
            if (oppMove == "A") {score += 2;}
            if (oppMove == "B") {score += 3;}
            if (oppMove == "C") {score += 1;}
        }
    }
    cout << score;
    return 0;
}
