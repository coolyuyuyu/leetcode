class Solution {
public:
    // Time: O(n), Space: O(n)
    int linearScan(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> existed(n + 1, false);
        for (int num : nums) {
            if (existed[num]) {
                return num;
            }
            existed[num] = true;
        }

        assert(false);
        return 0;
    }

    // Time: O(n), Space: O(1)
    int indexSort(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int i = 0; i <= n; ++i) {
            while (nums[i] != i + 1 && nums[i] - 1 <= n && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (nums[i] != i + 1) {
                return nums[i];
            }
        }

        assert(false);
        return 0;
    }

    // Time: O(nlogn), Space: O(1)
    int binaySearch(vector<int>& nums) {
        int n = nums.size() - 1;
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = std::count_if(nums.begin(), nums.end(), [&](int num){ return num <= mid; });
            if (cnt > mid) {
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
