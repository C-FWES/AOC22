//
// Created by wou on 22/12/22.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
    vector<vector<string>> pairs;
    vector<string> pair;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        stringstream str(line);
        while (str.good()) {
            string substr;
            getline(str, substr, ',');
            pair.push_back(substr);
        }
        pairs.push_back(pair);
        pair.clear();
    }

    int count = 0;

    for (int i = 0; i < pairs.size(); ++i) {
        vector<string> currPair = pairs[i];
        vector<string> subPair1;
        vector<string> subPair2;
        string firstHalf = currPair[0];
        string secondHalf = currPair[1];
        string a,b,c,d;
        stringstream str1(firstHalf);
        stringstream str2(secondHalf);
        while (str1.good()) {string sub1;
            getline(str1, sub1, '-');subPair1.push_back(sub1);}
        while (str2.good()) {string sub2;
            getline(str2, sub2, '-');subPair2.push_back(sub2);}
        a = subPair1[0];b = subPair1[1];c = subPair2[0];d = subPair2[1];
        if (stoi(a) <= stoi(c) and stoi(b) >= stoi(d)) {
            ++count;
        }
        else if (stoi(a) >= stoi(c) and stoi(b) <= stoi(d)) {
            ++count;
        }
    }
    cout << count;
    return 0;
}