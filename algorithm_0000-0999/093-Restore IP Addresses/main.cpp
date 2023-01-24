class Solution {
public:
    vector<string> bruteforce(const string& s) {
        vector<string> ret;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < (i + 4); ++j) {
                for (int k = j + 1; k < (j + 4); ++k) {
                    if (s.size() <= (k + 1) || (k + 4) < s.size()) {
                        continue;
                    }

                    string a = s.substr(0, i + 1);
                    if (255 < stoi(a) || to_string(stoi(a)) != a) {
                        continue;
                    }
                    string b = s.substr(i + 1, j - i);
                    if (255 < stoi(b) || to_string(stoi(b)) != b) {
                        continue;
                    }
                    string c = s.substr(j + 1, k - j);
                    if (255 < stoi(c) || to_string(stoi(c)) != c) {
                        continue;
                    }
                    string d = s.substr(k + 1);
                    if (255 < stoi(d) || to_string(stoi(d)) != d) {
                        continue;
                    }

                    ret.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }

        // s.size() == 11
        // 2 5 5 2 5 5 1 1 1 3 5
        //     i     j   k
        // 0 1 2 3 4 5 6 7 8 9 10
        return ret;
    }

    vector<string> restoreIpAddresses(string s) {
        return bruteforce(s);
    }
};
