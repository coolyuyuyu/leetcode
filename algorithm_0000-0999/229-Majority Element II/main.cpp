class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Majority Voting

        // At most 2 elements that appears more than (n / 3) times
        int num1 = INT_MIN, num2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == num1) {
                ++cnt1;
            }
            else if (num == num2) {
                ++cnt2;
            }
            else if (num1 != INT_MIN && num2 != INT_MIN) {
                if (--cnt1 == 0) {
                    num1 = INT_MIN;
                }
                if (--cnt2 == 0) {
                    num2 = INT_MIN;
                }
            }
            else if (num1 == INT_MIN) {
                num1 = num;
                cnt1 = 1;
            }
            else if (num2 == INT_MIN) {
                num2 = num;
                cnt2 = 1;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == num1) {
                ++cnt1;
            }
            else if (num == num2) {
                ++cnt2;
            }
        }

        vector<int> ret;
        if (cnt1 > (nums.size() / 3)) {
            ret.push_back(num1);
        }
        if (cnt2 > (nums.size() / 3)) {
            ret.push_back(num2);
        }

        return ret;
    }
};
