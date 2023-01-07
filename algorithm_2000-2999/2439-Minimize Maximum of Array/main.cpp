class Solution {
public:
    int binary_search(const vector<int>& nums) {
        auto isOk = [&nums](int maxNum) -> bool {
            for (long buf = 0, i = 0; i < nums.size(); ++i) {
                if (nums[i] <= maxNum) {
                    buf += (maxNum - nums[i]);
                }
                else {
                    buf -= (nums[i] - maxNum);
                    if (buf < 0) {
                        return false;
                    }
                }
            }
            return true;
        };

        int lft = 0, rht = *std::max_element(nums.begin(), nums.end());
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if (isOk(mid)) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return lft;
    }

    int prefix(const vector<int>& nums) {
        int ret = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ret = std::max(ret, (int)ceil(double(sum) / (i + 1)));
        }

        return ret;
    }

    int minimizeArrayValue(vector<int>& nums) {
        //return binary_search(nums);
        return prefix(nums);
    }
};
