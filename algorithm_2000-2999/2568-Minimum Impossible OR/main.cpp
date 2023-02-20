class Solution {
public:
    // Time: O(NlogN)
    int f1(vector<int>& nums) {
        // min impossible subset sum:
        // sorted nums:
        //     X X X X X X
        //         i

        // assume consider subarry nums[0, i-1] and possible subet sum is [1, m]
        // if (m + 1) < nums[i]:
        //     => it is impossible to form a subset sum as m + 1

        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int num : nums) {
            if ((ret + 1) < num) {
                break;
            }
            ret |= num;
        }

        return ret + 1;
    }

    // Time: O(N)
    int f2(const vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ret = 1;
        while (s.find(ret) != s.end()) {
            ret <<= 1;
        }

        return ret;
    }

    int minImpossibleOR(vector<int>& nums) {
        //return f1(nums);
        return f2(nums);
    }
};
