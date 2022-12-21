//
// Created by wou on 21/12/22.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main () {
    vector<vector<int>> calories;
    string line;
    vector<int> group;
    while (getline(cin, line)) {
        if (line.empty()) {
            calories.push_back(group);
            group.clear();
        }
        else {group.push_back(stoi(line));}
    }
    int max = -1;
    int curr = 0;
    for (int i = 0; i < calories.size(); i+=1) {
        int sumOfGroup = accumulate(calories[i].begin(), calories[i].end(), 0);
        curr = sumOfGroup;
        if (curr > max) {
            max = curr;
        }
    }
    cout << max;
    return 0;
}
