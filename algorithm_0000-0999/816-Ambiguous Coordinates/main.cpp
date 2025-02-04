class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        unordered_map<string, vector<string>> cache;
        std::function<vector<string>(const string&)> str2nums = [&](const string& str) {
            if (cache.find(str) != cache.end()) {
                return cache[str];
            }

            vector<string>& ret = cache[str];
            int n = str.size();
            if (n == 1) {
                ret.push_back(str);
            }
            else {
                if (str[0] == '0') {
                    if (str[n - 1] == '0') {
                    }
                    else {
                        string num = "0." + str.substr(1);
                        ret.push_back(num);
                    }
                }
                else {
                    ret.push_back(str);
                    if (str[n - 1] != '0') {
                        for (int i = 1; i < n; ++i) {
                            string num = str;
                            num.insert(i, ".");
                            ret.push_back(num);
                        }
                    }
                }
            }


            return ret;

        };

        vector<string> ret;
        for (int i = 1; i + 2 < s.size(); ++i) {
            string lft = s.substr(1, i);
            string rht = s.substr(i + 1, s.size() - i - 2);
            const vector<string>& lftNums = str2nums(lft);
            const vector<string>& rhtNums = str2nums(rht);
            for (const string& lftNum : lftNums) {
                for (const string& rhtNum: rhtNums) {
                    string str = "(" + lftNum + ", " + rhtNum + ")";
                    ret.push_back(str);
                }
            }
        }

        return ret;
    }
};
