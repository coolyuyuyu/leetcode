class Solution {
public:
    string byRecursion(vector<string>& nums) {
        unordered_set<int> numSet;
        for (const string& s : nums) {
            int num;
            std::from_chars(s.data(), s.data() + s.size(), num, 2);
            numSet.insert(num);
        }

        int n = nums.size();

        int num = 0;
        std::function<bool(int)> f = [&](int i) {
            if (i >= n) {
                return numSet.find(num) == numSet.end();
            }

            for (int d : {0, 1}) {
                num = (num << 1) + d;
                if (f(i + 1)) {
                    return true;
                }
                num >>= 1;
            }

            return false;
        };
        f(0);

        return std::bitset<16>(num).to_string().substr(16 - n);
    }

    string byRandom(vector<string>& nums) {
        unordered_set<int> numSet;
        for (const string& s : nums) {
            int num;
            std::from_chars(s.data(), s.data() + s.size(), num, 2);
            numSet.insert(num);
        }

        int n = nums.size();

        int num;
        do {
            num = std::rand() % (int)std::pow(2, n);

        } while (numSet.find(num) != numSet.end());

        return std::bitset<16>(num).to_string().substr(16 - n);
    }

    string byCantorDiagonalArgument(vector<string>& nums) {
        int n = nums.size();

        string ret(n, '\0');
        for (int i = 0; i < n; ++i) {
            ret[i] = '1' - nums[i][i] + '0';
        }

        return ret;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        //return byRecursion(nums);
        return byRandom(nums);
        //return byCantorDiagonalArgument(nums);
    }
};
