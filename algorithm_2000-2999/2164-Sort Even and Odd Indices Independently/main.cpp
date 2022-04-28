class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int, vector<int>, std::less<int>> maxHeap;
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 1) {
                maxHeap.push(nums[i]);
            }
            else {
                minHeap.push(nums[i]);
            }
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 1) {
                nums[i] = maxHeap.top();
                maxHeap.pop();
            }
            else {
                nums[i] = minHeap.top();
                minHeap.pop();
            }
        }

        return nums;
    }
};
