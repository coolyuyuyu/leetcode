class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;

        auto itr1 = word1.begin(), itr2 = word2.begin();
        while (itr1 != word1.end() && itr2!= word2.end()) {
            result.push_back(*itr1++);
            result.push_back(*itr2++);
        }
        result.append(itr1, word1.end());
        result.append(itr2, word2.end());

        return result;
    }
};