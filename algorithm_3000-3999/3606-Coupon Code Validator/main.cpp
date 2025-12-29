class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        std::function<bool(const string&, const string&, bool)> check = [](const string& code, const string& businessLine, bool isActive) {
            if (code.empty()) { return false; }
            if (!std::all_of(code.begin(), code.end(), [](char c){ return isalnum(c) || c == '_'; })) { return false;}
            if (businessLine != "electronics" && businessLine != "grocery" && businessLine != "pharmacy" && businessLine != "restaurant") { return false; }
            if (!isActive) { return false; }
            return true;
        };

        map<string, vector<string>> selectedCodes;
        for (int i = 0, n = code.size(); i < n; ++i) {
            if (check(code[i], businessLine[i], isActive[i])) {
                selectedCodes[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> ret;
        for (auto& [_, codes] : selectedCodes) {
            std::sort(codes.begin(), codes.end());
            std::copy(codes.begin(), codes.end(), std::back_inserter(ret));
        }

        return ret;
    }
};
