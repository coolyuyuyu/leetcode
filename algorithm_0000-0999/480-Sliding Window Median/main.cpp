class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        for (int i = 0; i < k; ++i) {
            ms.insert(nums[i]);
        }
        // X, 1 => 0
        // XO, 2 => 0
        // OXO, 3 => 1
        // OXOO 4 => 1
        auto itr = std::next(ms.begin(), (k - 1) / 2);

        vector<double> ret;
        ret.push_back((k & 1) ? (*itr) : (*itr * 0.5 + *std::next(itr) * 0.5));
        for (int i = k, n = nums.size(); i < n; ++i) {
            ms.insert(nums[i]);
            if (k & 1) {
                // 0, OOXOO
                // 1. OOOXOO, less then m
                //      move prev
                // 2. OOXOOO, greater than m
                //      do nothing
                // 3, OOXOOO, equal
                //      will be inserted after m, do nothing
                if (nums[i] < *itr) {
                    itr = std::prev(itr);
                }
                else if (nums[i] > *itr) {
                }
                else {
                }

                // 0. OOXOOO
                // 1. OXOOO, less than m
                //      move next
                // 2. OOXOO, greater than m
                //      do nothing
                // 3.
                if (nums[i - k] < *itr) {
                    itr = std::next(itr);
                    ms.erase(ms.lower_bound(nums[i - k]));
                }
                else if (nums[i - k] > *itr) {
                    ms.erase(ms.lower_bound(nums[i - k]));
                }
                else {
                    auto toRemoved = ms.lower_bound(nums[i - k]);
                    if (toRemoved == itr) {
                        itr = ms.erase(toRemoved);
                    }
                    else {
                        itr = std::next(itr);
                        ms.erase(toRemoved);
                    }
                }
            }
            else {
                // 0, OOXOOO
                // 1. OOOXOOO, less then m
                //      do nothing
                // 2. OOXOOOO, greater than m
                //      move next
                // 3, OOXOOOO, equal
                //      will be inserted after m, move next
                if (nums[i] < *itr) {
                }
                else if (nums[i] > *itr) {
                    itr = std::next(itr);
                }
                else {
                    itr = std::next(itr);
                }

                // 0. OOOXOOO
                // 1. OOXOOO, less than m
                //     do nothing
                // 2. OOOXOO, greater than m
                //      move prev
                // 3.
                if (nums[i - k] < *itr) {
                    ms.erase(ms.lower_bound(nums[i - k]));
                }
                else if (nums[i - k] > *itr) {
                    itr = std::prev(itr);
                    ms.erase(ms.lower_bound(nums[i - k]));
                }
                else {
                    auto toRemoved = ms.lower_bound(nums[i - k]);
                    if (toRemoved == itr) {
                        itr = ms.erase(toRemoved);
                        itr = std::prev(itr);
                    }
                    else {
                        ms.erase(toRemoved);
                    }
                }
            }

            ret.push_back((k & 1) ? (*itr) : (*itr * 0.5 + *std::next(itr) * 0.5));
        }

        return ret;
    }
};
