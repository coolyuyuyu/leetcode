class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        std::function<int(int)> reverse = [](int num) {
            int ret = 0;
            for (; num; num /= 10) {
                ret = ret * 10 + num % 10;
            }
            return ret;
        };

        int ret = INT_MAX;
        unordered_map<int, int> num2idx;
        for (int i = nums.size(); 0 < i--;) {
            auto itr = num2idx.find(reverse(nums[i]));
            if (itr != num2idx.end()) {
                ret = std::min(ret, (itr->second - i));
            }
            num2idx[nums[i]] = i;
        }

        return ret < INT_MAX ? ret : -1;
    }
};
