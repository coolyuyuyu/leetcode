class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        assert(2 <= nums.size());

        set<int> s;
        for (int num : nums) {
            if (num % 2) { // odd
                s.insert(num * 2);
            }
            else {
                s.insert(num);
            }
        }

        int ret = INT_MAX;
        while (true) {
            ret = std::min(ret, *s.rbegin() - *s.begin());    

            int num = *s.rbegin();
            s.erase(std::prev(s.end()));
            if (num % 2) {
                break;
            }
            s.insert(num / 2);
        }

        return ret;
    }
};
