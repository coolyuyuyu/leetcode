class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for (size_t i = 0; i < 2; ++i) {
            minHeap.push(nums[i]);
            maxHeap.push(nums[i]);
        }

        minHeap.push(nums[2]);
        if (nums[2] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(nums[2]);
        }

        for (size_t i = 3; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            if (nums[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
        }

        int max3rd = minHeap.top();
        minHeap.pop();
        int max2nd = minHeap.top();
        minHeap.pop();
        int max1st = minHeap.top();
        minHeap.pop();

        int min2nd = maxHeap.top();
        maxHeap.pop();
        int min1st = maxHeap.top();
        minHeap.pop();


        return max(max3rd * max2nd * max1st, min1st * min2nd * max1st);
    }
};
