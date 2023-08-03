class Solution {
public:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> recursive(const string& digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> ret;
        string comb;
        std::function<void()> f = [&]() {
            if (digits.size() <= comb.size()) {
                ret.push_back(comb);
                return;
            }

            for (char c : letters[digits[comb.size()] - '0']) {
                comb.push_back(c);
                f();
                comb.pop_back();
            }
        };
        f();

        return ret;
    }

    vector<string> itertive(const string& digits) {
        if (digits.empty()) {
            return {};
        }

        queue<string> q({""});
        for (char digit : digits) {
            for (int n = q.size(); 0 < n--;) {
                string comb = q.front();
                q.pop();

                for (char c : letters[digit - '0']) {
                    string tmp = comb;
                    tmp.push_back(c);
                    q.push(tmp);
                }
            }
        }

        vector<string> ret;
        for (; !q.empty(); q.pop()) {
            ret.push_back(q.front());
        }

        return ret;
    }

    vector<string> letterCombinations(string digits) {
        //return recursive(digits);
        return itertive(digits);
    }
};
