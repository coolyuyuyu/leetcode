class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ret;
        for (const string& word : words) {
            int sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            sum %= 26;

            ret += ('z' - sum);
        }

        return ret;
    }
};
