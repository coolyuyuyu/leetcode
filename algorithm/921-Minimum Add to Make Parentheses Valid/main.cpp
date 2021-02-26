class Solution {
public:
    int minAddToMakeValid(string S) {
        int num = 0;
        int open = 0;
        for (char c : S) {
            if (c == '(') {
                ++open;
            }
            else {
                if (open == 0) {
                    ++num;
                }
                else {
                    --open;
                }
            }
        }

        return (num + open);
    }
};