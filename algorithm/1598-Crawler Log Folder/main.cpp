class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (const string& log : logs) {
            if (log == "../") {
                if (count) {
                    --count;
                }
            }
            else if (log == "./") {
            }
            else {
                ++count;
            }
        }

        return count;
    }
};