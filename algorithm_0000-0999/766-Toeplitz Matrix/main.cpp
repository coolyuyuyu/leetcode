class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> dict;
        for (const string& word : words) {
            string morse;
            for (char c : word) {
                morse += codes[c - 'a'];
            }
            dict.insert(morse);
        }

        return dict.size();
    }
};
