class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> counts;
        for (const string& str : {A, B}) {
            size_t pos = str.find_first_not_of(' ');
            do {
                size_t newPos = str.find_first_of(' ', pos);
                counts[str.substr(pos, newPos - pos)]++;
                pos = str.find_first_not_of(' ', newPos);
            } while (pos < str.size());
            
        }

        vector<string> result;
        for (const auto& elem : counts) {
            if (elem.second == 1) {
                result.push_back(elem.first);
            }
        }

        return result;
    }
};