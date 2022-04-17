class Solution {
public:
    // Time: O(1), Space: O(1)
    int maximumProduct_Linear(vector<int>& nums) {
        // assume sorted nums: min1, min2, ..., max3, max2, max1
        int min1 = INT_MAX, min2 = INT_MAX;
        int max3 = INT_MIN, max2 = INT_MIN, max1 = INT_MIN;

        for (int num : nums) {
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }

            if (max1 <= num) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (max2 <= num) {
                max3 = max2;
                max2 = num;
            }
            else if (max3 < num){
                max3 = num;
            }
        }

        return std::max(max3 * max2 * max1, min1 * min2 * max1);
    }

    // Time: O(1), Space: O(1)
    int maximumProduct_Heap(vector<int>& nums) {
        // assume sorted nums: min1, min2, ..., max3, max2, max1
        // maxHeap for min2, min1
        // minHeap for max3, max2, max1
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for (int num : nums) {
            if (minHeap.size() < 3) {
                minHeap.push(num);
            }
            else if (minHeap.top() < num) {
                minHeap.pop();
                minHeap.push(num);
            }

            if (maxHeap.size() < 2) {
                maxHeap.push(num);
            }
            else if (num < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(num);
            }
        }

        int min2 = maxHeap.top(); maxHeap.pop();
        int min1 = maxHeap.top(); maxHeap.pop();
        int max3 = minHeap.top(); minHeap.pop();
        int max2 = minHeap.top(); minHeap.pop();
        int max1 = minHeap.top(); minHeap.pop();

        return std::max(max3 * max2 * max1, min1 * min2 * max1);
    }

    int maximumProduct(vector<int>& nums) {
        //return maximumProduct_Linear(nums);
        return maximumProduct_Heap(nums);
    }
};
