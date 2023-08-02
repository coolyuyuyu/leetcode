class Solution {
public:
    // 隔板法
    vector<vector<int>> f1(const vector<int>& nums) {
        queue<vector<int>> q({{}});
        for (int num : nums) {
            for (int n = q.size(); 0 < n--; ) {
                vector<int> perm = q.front();
                q.pop();

                for (int i = 0; i <= perm.size(); ++i) {
                    vector<int> tmp = perm;
                    tmp.insert(tmp.begin() + i, num);
                    q.push(tmp);
                }
            }
        }

        vector<vector<int>> ret;
        for (; !q.empty(); q.pop()) {
            ret.push_back(q.front());
        }

        return ret;
    }

    // 自幹 next_permutation
    vector<vector<int>> f2(vector<int>& nums) {
        std::function<bool(vector<int>&)> nextPermutation = [](vector<int>& nums) {
            size_t i;
            for (i = nums.size(); 1 < i--;) {
                if (nums[i - 1] < nums[i]) {
                    break;
                }
            }

            if (i-- == 0) {
                return false;
            }

            size_t j;
            for (j = nums.size(); i < j--;) {
                if (nums[i] < nums[j]) {
                    break;
                }
            }
            std::swap(nums[i], nums[j]);
            std::sort(nums.begin() + i + 1, nums.end());


            return true;
        };

        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while (nextPermutation(nums));

        return ret;
    }

    // std next_permutation
    vector<vector<int>> f3(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return ret;
    }

    // recursive append
    vector<vector<int>> recursion1(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> perm;
        vector<int> used(nums.size(), false);
        std::function<void()> f = [&]() {
            if (nums.size() <= perm.size()) {
                ret.push_back(perm);
            }
            else {
                for (size_t i = 0; i < nums.size(); ++i) {
                    if (!used[i]) {
                        used[i] = true;
                        perm.push_back(nums[i]);

                        f();

                        perm.pop_back();
                        used[i] = false;
                    }

                }
            }
        };
        f();

        return ret;
    }

    // recursive swap
    vector<vector<int>> recursion2(vector<int>& nums) {
        vector<vector<int>> ret;
        std::function<void(size_t)> f = [&](size_t start) {
            if (nums.size() <= start) {
                ret.push_back(nums);
            }
            else {
                for (size_t i = start; i < nums.size(); ++i) {
                    std::swap(nums[start], nums[i]);
                    f(start + 1);
                    std::swap(nums[start], nums[i]);
                }
            }
        };
        f(0);

        return ret;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //return f1(nums);
        //return f2(nums);
        //return f3(nums);
        //return recursion1(nums);
        return recursion2(nums);
    }
};
