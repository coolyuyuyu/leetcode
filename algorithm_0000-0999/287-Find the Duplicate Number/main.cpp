class Solution {
public:
    // Time: O(n), Space: O(n)
    int linearScan(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flags(n, false);
        for (int num : nums) {
            if (flags[num - 1]) {
                return num;
            }
            flags[num - 1] = true;
        }

        return 0;
    }

    // Time: O(n), Space: O(1)
    int indexSort(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                std::swap(nums[i], nums[nums[i]]);
            }

            if (nums[i] != i) {
                return nums[i];
            }
        }

        return 0;
    }

    // Time: O(nlogn), Space: O(1)
    int binaySearch(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = std::count_if(nums.begin(), nums.end(), [&](int num) { return num <= mid; });//0;
            if (mid < cnt) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Time: O(n), Space: O(1)
    int cycleDetect(vector<int>& nums) {
        // 142. Linked List Cycle II

        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    int findDuplicate(vector<int>& nums) {
        //return linearScan(nums);
        //return indexSort(nums);
        //return binaySearch(nums);
        return cycleDetect(nums);
    }
};
