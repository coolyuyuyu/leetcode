class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str;
        for (const string& word : sentence) {
            str += word;
            str += " ";
        }
        int len = str.size();

        int idx = 0;
        for (int r = 0; r < rows; ++r) {
            idx += cols;
            while (str[idx% len] != ' ') {
                if (idx == 0) {
                    return 0;
                }
                --idx;
            }

            ++idx;
        }

        return idx / len;
    }
};
