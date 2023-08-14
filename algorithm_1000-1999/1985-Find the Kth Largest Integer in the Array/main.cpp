class Solution {
public:
    static bool comp(const string& num1, const string& num2) {
        return num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2);
    };

    // Time: O(NlogN)
    string quickSort(vector<string>& nums, int k) {
        std::sort(nums.begin(), nums.end(), comp);
        return nums[k];
    }

    // Time: O(NlogK)
    string heap(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, decltype(&comp)> pq(comp);
        for (const string& num : nums) {
            pq.push(num);
            if ((k + 1) < pq.size()) {
                pq.pop();
            }
        }

        return pq.top();
    }

    // Time: O(NlogC)
    string binarySearch(vector<string>& nums, int k) {
        auto [pLo, pHi] = std::minmax_element(nums.begin(), nums.end(), comp);
        auto lo = *pLo, hi = *pHi;

        std::function<string(string, string)> add = [](string num1, string num2) {
            string ret(std::max(num1.size(), num2.size()), '\0');
            bool carry = false;
            for (auto itr1 = num1.rbegin(), itr2 = num2.rbegin(), itr = ret.rbegin(); itr != ret.rend(); ++itr) {
                int d = (carry ? 1 : 0);
                if (itr1 != num1.rend()) { d += *itr1++ - '0'; }
                if (itr2 != num2.rend()) { d += *itr2++ - '0'; }
                *itr = ('0' + (d % 10));
                carry = (10 <= d);
            }
            if (carry) {
                ret.insert(ret.begin(), '1');
            }

            return ret;
        };
        std::function<string(string)> half = [](string num) -> string {
            bool carry = false;
            for (char& c : num) {
                int d = (c - '0') + (carry ? 10 : 0); 
                c = '0' + d / 2;
                carry = d & 1;
            }

            auto itr = num.begin();
            while (itr != num.end() && *itr == '0') {
                ++itr;
            }

            return itr == num.end() ? "0" : string(itr, num.end());
        };
        std::function<int(const string&)> countLE = [&nums, k](const string& target) {
            int cnt = 0;
            for (const string& num : nums) {
                if (!comp(target, num)) {
                    ++cnt;
                }
            }

            return cnt;
        };
        while (comp(lo, hi)) {
            string mid = half(add(lo, hi));
            if (k < countLE(mid)) {
                hi = mid;
            }
            else {
                lo = add(mid, "1");
            }
        }

        return lo;
    }

    // Time: Amoterized O(N)
    string quickSelect(vector<string>& nums, int k) {
        std::function<string(int, int, int)> f = [&](int lo, int hi, int k) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
            string pivot = nums[lo + (hi - lo) / 2];
            int i = lo, j = hi, x = lo;
            while (x <= j) {
                if (comp(nums[x], pivot)) {
                    std::swap(nums[i], nums[x]);
                    ++i;
                    ++x;
                }
                else if (!comp(pivot, nums[x])) {
                    ++x;
                }
                else {
                    std::swap(nums[x], nums[j]);
                    --j;
                }
            }
            // S S S S S M M M M M L L L L L
            // lo        i       j         hi
            if (k < (i - lo)) {
                return f(lo, i - 1, k);
            }
            else if (k < (j + 1 - lo)) {
                return pivot;
            }
            else {
                return f(j + 1, hi, k - (j + 1 - lo));
            }
        };

        return f(0, nums.size() - 1, k);
    }

    string kthSmallestNumber(vector<string>& nums, int k) {
        //return quickSort(nums, k);
        //return heap(nums, k);
        //return binarySearch(nums, k);
        return quickSelect(nums, k);
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        return kthSmallestNumber(nums, nums.size() - k);
    }
};
