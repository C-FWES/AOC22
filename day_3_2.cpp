//
//created by wou on 22/12/22
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

char getUniqueItem(const string& first, const string& second, const string& third) {
    char item = 0;
    for (int k = 0; k < first.length(); ++k) {
        string curr;
        curr += first[k];
        if (second.find(curr) != string::npos and third.find(curr) != string::npos) {
            item = first[k];
            break;
        }
    }
    return item;
}

int main() {
    vector<vector<string>> rucksacks;
    string line;
    map<string, int> letterPriorities = {{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"E", 5},
                                         {"f", 6}, {"g", 7}, {"h", 8}, {"i", 9}, {"j", 10},
                                         {"k", 11}, {"l", 12}, {"m", 13}, {"n", 14}, {"o", 15},
                                         {"p", 16}, {"q", 17}, {"r", 18}, {"s", 19}, {"t", 20},
                                         {"u", 21}, {"v", 22}, {"w", 23}, {"x", 24}, {"y", 25}, {"z", 26}};
    int count = 3;
    vector<string> elfGroup;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        elfGroup.push_back(line);
        count -= 1;
        if (count == 0) {rucksacks.push_back(elfGroup); elfGroup.clear(); count = 3;}
    }

    int sum = 0;

    for (int i = 0; i < rucksacks.size(); ++i) {
        vector<string> group = rucksacks[i];
        string firstSack = group[0];
        string secondSack = group[1];
        string thirdSack = group[2];
        char foundItem = getUniqueItem(firstSack, secondSack, thirdSack);
        string letter;
        letter += foundItem;
        if (::islower(foundItem)) {sum += letterPriorities[letter];}
        else {string lowerLetter; for (auto elem: letter) {char converted = ::tolower(elem);
        lowerLetter += converted;}sum+=letterPriorities[lowerLetter];sum+=26;}
    }
    cout << sum;
    return 0;
}
