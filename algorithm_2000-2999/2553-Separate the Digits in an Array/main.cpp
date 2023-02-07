class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for (int num : nums) {
            string s = std::to_string(num);
            for (char c : s) {
                ret.push_back(c - '0');
            }
        }

        return ret;
    }
};
