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
        int majority, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                majority = num;
                cnt = 1;
            }
            else {
                majority == num ? ++cnt : --cnt;
            }

        }

        return majority;
    }

    int majorityElement(vector<int>& nums) {
        //return majorityElement_HashCount(nums);
        return majorityElement_Linear(nums);
    }
};
