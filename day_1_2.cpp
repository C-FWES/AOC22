//
// Created by wou on 21/12/22.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main () {
    vector<vector<int>> calories;
    string line;
    vector<int> group;
    while (getline(cin,line)) {
        if (line == "bruh") {
            break;
        }
        if (line.empty()) {
            calories.push_back(group);
            group.clear();
        }
        else {group.push_back(stoi(line));}
    }
    vector<int> sums;
    int top3 = 0;
    for (int i = 0; i < calories.size(); i+=1) {
        int sumOfGroup = accumulate(calories[i].begin(), calories[i].end(), 0);
        sums.push_back(sumOfGroup);
    }
    sort(sums.begin(), sums.end(), greater<int>());
    top3 = sums[0] + sums[1] + sums[2];
    cout << top3;
    return 0;
}
