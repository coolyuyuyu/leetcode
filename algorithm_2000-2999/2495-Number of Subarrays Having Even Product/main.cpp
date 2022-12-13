class Solution {
public:
    // TLE
    long long f1(vector<int>& nums) {
        for (int& num : nums) {
            num = num % 2 ? 0 : 1;
        }

        map<int, int> m; // key: presum => val: how many prefix
        m[0] = 1;

        long long ret = 0;
        for (int presum = 0, i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            for (const auto& [sum, cnt] : m) {
                if (presum <= sum) {
                    break;
                }
                ret += cnt;
            }

            ++m[presum];
        }

        return ret;
    }

    // optimized from f1
    long long f2(vector<int>& nums) {
        long long ret = 0;
        int cntSoFar = 0, cnt = 1;
        for (int num : nums) {
            if (num % 2) {
                ret += cntSoFar;
                cnt++;
            }
            else {
                cntSoFar += cnt;
                ret += cntSoFar;
                cnt = 1;
            }
        }

        return ret;
    }

    // for each i, check the left-nearest index of even number
    long long f3(vector<int>& nums) {
        long long ret = 0;
        for (int lastEvenIndex = -1, i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                lastEvenIndex = i;
            }
            ret += (lastEvenIndex + 1);
        }

        return ret;
    }

    long long evenProduct(vector<int>& nums) {
        //return f1(nums);
        //return f2(nums);
        return f3(nums);
    }
};

/*
even * even = even
odd * even = even
odd * odd = odd

odd => 0, even => 1
X X X X X X X X
        j     i
product of subarray[j=+1, i] is even
=> sum[j+1,i] > 0
=> (presum[i] - presum[j]) > 0
*/
