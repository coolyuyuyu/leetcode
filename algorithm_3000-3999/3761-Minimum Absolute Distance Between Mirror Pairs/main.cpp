class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        std::function<int(int)> reverseNum = [](int num) {
            int ret = 0;
            for (; num; num /= 10) {
                ret *= 10;
                ret += num % 10;
            }
            return ret;
        };

        int ret = INT_MAX;

        unordered_map<int, int> num2idx;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int revNum = reverseNum(nums[i]);
            auto itr = num2idx.find(revNum);
            if (itr != num2idx.end()) {
                ret = std::min(ret, itr->second - i);
            }
            num2idx[nums[i]] = i;
        }

        return ret != INT_MAX ? ret : -1;
    }
};
