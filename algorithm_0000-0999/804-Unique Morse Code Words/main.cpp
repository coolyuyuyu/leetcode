class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static vector<string> codes {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> dict;
        for (size_t i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            string codedWord;
            for (size_t j = 0; j < word.size(); ++j) {
                codedWord += codes[word[j] - 'a'];
            }

            dict.insert(codedWord);
        }

        return dict.size();
    }
};