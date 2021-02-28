class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> counts(26, 0);
        string::iterator slow = s.begin();
        string::iterator fast = s.begin();
        while (fast != s.end()) {
            ++counts[*fast - 'a'];
            while (slow <= fast && 1 < counts[*slow - 'a']) {
                ++slow;
            }
            ++fast;
        }

        if (slow == s.end()) {
            return -1;
        }
        else {
            return slow - s.begin();
        }
    }
};