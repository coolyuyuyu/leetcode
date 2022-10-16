class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            int num = *itr;
            if (0 <= num) {
                break;
            }

            if (s.find(-num) != s.end()) {
                return -num;
            }
        }

        return -1;
    }
};
