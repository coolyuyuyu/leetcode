class Solution {
public:
    bool check(const string& code, const string& businessLine, bool isActive) {
        if (code.empty()) { return false; }
        if (!std::all_of(code.begin(), code.end(), [](char c){ return std::isalnum(c) || c == '_'; })) { return false; }
        if (businessLine != "electronics" && businessLine != "grocery" && businessLine != "pharmacy" && businessLine != "restaurant") { return false; }
        if (!isActive) { return false;}
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        map<string, vector<string>> selected;
        for (int i = 0; i < n; ++i) {
            if (!check(code[i], businessLine[i], isActive[i])) { continue; }
            selected[businessLine[i]].push_back(code[i]);
        }

        vector<string> ret;
        for (auto& [_, coupons] : selected) {
           std::sort(coupons.begin(), coupons.end());
           ret.insert(ret.end(), coupons.begin(), coupons.end());
        }

        return ret;
    }
};
