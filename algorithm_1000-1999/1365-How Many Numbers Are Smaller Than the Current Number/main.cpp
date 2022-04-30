class Solution {
public:
    vector<int> bySort(vector<int>& nums) {
        vector<int> tmps = nums;
        std::sort(tmps.begin(), tmps.end());

        vector<int> cnts(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            cnts[i] = std::lower_bound(tmps.begin(), tmps.end(), nums[i]) - tmps.begin();
        }

        return cnts;
    }

    vector<int> byCnt(vector<int>& nums) {
        vector<int> cnts(101, 0);
        for (int num : nums) {
            ++cnts[num];
        }
        std::partial_sum(cnts.begin(), cnts.end(), cnts.begin());

        vector<int> ans(nums.size());
        for (size_t i = 0; i < ans.size(); ++i) {
            ans[i] = (nums[i] == 0 ? 0 : cnts[nums[i] - 1]);
        }

        return ans;
    }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //return bySort(nums);
        return byCnt(nums);
    }
};
