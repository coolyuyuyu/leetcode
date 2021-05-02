class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<char> counts(26);
        for (char c : chars) {
            ++counts[c - 'a'];
        }

        int count = 0;
        for (const string& word : words) {
            vector<char> countsTmp(counts);

            bool good = true;
            for (char c : word) {
                if (countsTmp[c - 'a'] == 0) {
                    good = false;
                    break;
                }
                --countsTmp[c - 'a'];
            }

            if (good) {
                count += word.size();
            }
        }

        return count;
    }
};
