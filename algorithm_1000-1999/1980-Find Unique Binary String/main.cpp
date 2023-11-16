class Solution {
public:
    string findLowestDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        priority_queue<string, vector<string>, std::greater<string>> pq;
        for (const string& num : nums) {
            pq.push(num);
        }

        std::function<void(string&)> increment = [](string& num) {
            for (int i = num.size(), carry = 1; 0 < i--;) {
                num[i] += carry;
                carry = (num[i] - '0') / 2;
                num[i] = '0' + (num[i] - '0') % 2;
            }
        };

        string cur(n, '1');
        for (; !pq.empty(); pq.pop()) {
            increment(cur);
            if (cur != pq.top()) {
                return cur;
            }
        }

        increment(cur);
        return cur;
    }

    string CantorDiadonalArgument(vector<string>& nums) {
        string ret(nums.size(), '\0');
        for (int i = 0; i < nums.size(); ++i) {
            ret[i] = (nums[i][i] == '1' ? '0' : '1');
        }

        return ret;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        //return findLowestDifferentBinaryString(nums);
        return CantorDiadonalArgument(nums);
    }
};
