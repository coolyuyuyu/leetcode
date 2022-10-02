class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> prevIndexes(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int charIndex = s[i] - 'a';
            if (prevIndexes[charIndex] < 0) {
                prevIndexes[charIndex] = i;
            }
            else {
                if ((i - prevIndexes[charIndex]) != (distance[charIndex] + 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};
