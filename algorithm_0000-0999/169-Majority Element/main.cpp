class Solution {
public:
    int majorityElement_HashCount(vector<int>& nums) {
        int halfSize = nums.size() / 2;
        unordered_map<int, int> counts;
        for (int num : nums) {
            if (++counts[num] > halfSize) {
                return num;
            }
        }

        assert(false);
        return 0;
    }

    // Boyer-Moore majority vote algorithm
    int majorityElement_Linear(vector<int>& nums) {
        int maj = 0, cnt = 1;
        for (int num : nums) {
            cnt += (num == maj ? 1 : -1);
            if (cnt == 0) {
                maj = num, cnt = 1;
            }
        }

        return maj;
    }

    int majorityElement(vector<int>& nums) {
        //return majorityElement_HashCount(nums);
        return majorityElement_Linear(nums);
    }
};
