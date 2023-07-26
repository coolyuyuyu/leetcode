class Solution {
public:
    // Time: O(n^2)
    int f1(const vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> s(1001, false);
            int cnt = -1;
            for (int j = i; j < n; ++j) {
                if (!s[nums[j]]) {
                    ++cnt;
                    if (s[nums[j] + 1]) {
                        --cnt;
                    }
                    if (s[nums[j] - 1]) {
                        --cnt;
                    }

                    s[nums[j]] = true;
                }

                ret += cnt;
            }
        }

        return ret;
    }

    // Time: O(n^2)
    int f2(const vector<int>& nums) {
        // count subarray by element
        // 4 [X X 5 X X X X 3 X 6 X X X X] 3
        // A      C         i   D          B

        // subarray cannot contain "nums[i] + 1" before and after i
        // subarray cannot contain "nums[i]" after i

        // A: preInvalid
        // B: nxtInvalid
        // C: preGTone
        // D: nxtGTone
        // => (i - A) * (B - i) - (i - C) * (D - i)

        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int preInvalid = -1, preGTone = -1;
            for (int j = i; 0 < j--;) {
                if (nums[j] == (nums[i] + 1)) {
                    preInvalid = j;
                    break;
                }

                if (1 < (nums[j] - nums[i]) && preGTone == -1) {
                    preGTone = j;
                }
            }

            int nxtInvalid = n, nxtGTone = n;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == (nums[i] + 1) || nums[j] == nums[i]) {
                    nxtInvalid = j;
                    break;
                }

                if (1 < (nums[j] - nums[i]) && nxtGTone == n) {
                    nxtGTone = j;
                }
            }

            ret += (i - preInvalid) * (nxtInvalid - i);
            ret -= (i - std::max(preGTone, preInvalid)) * (std::min(nxtGTone, nxtInvalid) - i);
        }

        return ret;
    }

    // Time: O(n^3)
    int f3(const vector<int>& nums) {
        // f2 improvement

        int n = nums.size();

        vector<int> num2pos;

        vector<int> preInvalid(n);
        num2pos.assign(1001 + 1, -1);
        for (int i = 0; i < n; ++i) {
            preInvalid[i] = num2pos[nums[i] + 1];
            num2pos[nums[i]] = i;
        }

        vector<int>nxtInvalid(n+1, n);
        num2pos.assign(1001 + 1, n);
        for (int i = n; 0 < i--;)
        {
            nxtInvalid[i] = min(num2pos[nums[i]], num2pos[nums[i] + 1]);
            num2pos[nums[i]] = i;
        }

        stack<int> stk;

        vector<int>preGTone(n, -1);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i] + 1) {
                stk.pop();
            }
            if (!stk.empty()) {
                preGTone[i] = stk.top();
            }

            stk.push(i);
        }

        vector<int>nxtGTone(n, n);
        while (!stk.empty()) { stk.pop(); }
        for (int i = n; 0 < i--;) {
            while (!stk.empty() && nums[stk.top()] <= nums[i] + 1) {
                stk.pop();
            }
            if (!stk.empty()) {
                nxtGTone[i] = stk.top();
            }

            stk.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += (i - preInvalid[i]) * (nxtInvalid[i] - i);
            ret -= (i - std::max(preGTone[i], preInvalid[i])) * (std::min(nxtGTone[i], nxtInvalid[i]) - i);
        }

        return ret;
    }

    int sumImbalanceNumbers(vector<int>& nums) {
        //return f1(nums);
        //return f2(nums);
        return f3(nums);
    }
};
