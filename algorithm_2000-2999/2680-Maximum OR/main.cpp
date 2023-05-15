class Solution {
public:
    long long greedy(const vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sumFwd(n); // sumFwd[i]: or(nums[0], nums[1], ... nums[i])
        for (int i = 0, sum = 0; i < n; ++i) {
            sum |= nums[i];
            sumFwd[i] = sum;
        }

        vector<int> sumBwd(n); // sumBwd[i]: or(nums[i], nums[i+1], ... nums[n-1])
        for (int i = n, sum = 0; 0 < i--;) {
            sum |= nums[i];
            sumBwd[i] = sum;
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            long long  val = 0;
            if (0 < i) {
                val |= sumFwd[i - 1];
            }
            val |= (static_cast<long long>(nums[i]) << k);
            if ((i + 1) < n) {
                val |= sumBwd[i + 1];
            }

            ret = std::max(ret, val);
        }

        return ret;
    }

    long long bit(const vector<int>& nums, int k) {
        vector<int> cnts(32, 0);
        for (int num : nums) {
            for (int i = 0; num; ++i, num >>= 1) {
                if (num & 1) {
                    ++cnts[i];
                }
            }
        }

        long long ret = 0;
        for (int num : nums) {
            vector<int> tmp = cnts;

            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    --tmp[i];
                }
            }

            long long val = (static_cast<long long>(num) << k);
            for (int i = 0; i < 32; ++i) {
                if (tmp[i]) {
                    val |= (1 << i);
                }
            }

            ret = std::max(ret, val);
        }

        return ret;
    }

    long long maximumOr(vector<int>& nums, int k) {
        //return greedy(nums, k);
        return bit(nums, k);
    }
};
