class Solution {
public:
    string betterCompression(string compressed) {
        map<char, int> cnts;
        for (int i = 0; i < compressed.size();) {
            char c = compressed[i];

            int cnt = 0;
            for (++i; i < compressed.size() && isdigit(compressed[i]); ++i) {
                cnt = cnt * 10 + (compressed[i] - '0');
            }

            cnts[c] += cnt;
        }

        string ret;
        for (const auto& [c, cnt] : cnts) {
            ret += c;
            ret += std::to_string(cnt);
        }

        return ret;
    }
};
