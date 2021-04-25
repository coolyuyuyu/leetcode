class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int keyIndex;
        if (ruleKey == "type") {
            keyIndex = 0;
        }
        else if (ruleKey == "color") {
            keyIndex = 1;
        }
        else if (ruleKey == "name") {
            keyIndex = 2;
        }

        auto pred = [&keyIndex, &ruleValue](const vector<string>& item) {
            return (item[keyIndex] == ruleValue);
        };
        return count_if(items.begin(), items.end(), pred);
    }
};
