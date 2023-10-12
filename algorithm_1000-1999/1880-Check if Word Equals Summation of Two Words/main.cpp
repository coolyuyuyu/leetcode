class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto toInt = [](const string& word) -> int {
            int ret = 0;
            for (int i = 0; i < word.size(); ++i) {
                ret *= 10;
                ret += word[i] - 'a';
            }

            return ret;
        };

        return (toInt(firstWord) + toInt(secondWord)) == toInt(targetWord);
    }
};
