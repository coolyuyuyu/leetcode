class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> cnts;
        for (const string& word : words) {
            cnts[word] += 1;
        }

        int ret = 0;
        bool flag = false;;
        for (const auto& [key, cnt] : cnts) {
            if (key[0] > key[1]) { continue; }
            else if (key[0] == key[1]) {
                ret += ((cnt / 2) * 2 * 2);
                if (cnt & 1) {
                    flag = true;
                }
            }
            else {
                string key2;
                key2 += key[1];
                key2 += key[0];
                int cnt2 = 0;
                if (cnts.find(key2) != cnts.end()) {
                    cnt2 = cnts[key2];
                }
                ret += std::min(cnt, cnt2) * 2 * 2;
            }
        }

        return ret + (flag ? 2 : 0);
    }
};
