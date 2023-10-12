class Solution {
public:
    int minTimeToType(string word) {
        int ret = word.size() + std::min(word[0] - 'a', 'z' - word[0] + 1);
        for (int i = 1; i < word.size(); ++i) {
            int diff = abs(word[i] - word[i - 1]);
            ret += std::min(diff, 26 - diff);
        }

        return ret;
    }
};
