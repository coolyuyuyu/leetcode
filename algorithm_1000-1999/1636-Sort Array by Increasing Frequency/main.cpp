class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> counts(201, 0);
        for (int num : nums) {
            if (num < 0) {
                num = 100 - num;
            }
            ++counts[num];
        }

        auto comp = [&counts](int num1, int num2) {
            int id1 = num1, id2 = num2;
            if (id1 < 0) {
                id1 = 100 - id1;
            }
            if (id2 < 0) {
                id2 = 100 - id2;
            }

            if (counts[id1] == counts[id2]) {
                return (num2 < num1);
            }
            else {
                return (counts[id1] < counts[id2]);
            }

        };
        sort(nums.begin(), nums.end(), comp);

        return nums;
    }
};
