class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t index = 0;
        for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == val)
                continue;
            nums[index++] = *iter;
        }
        return index;
    }
};