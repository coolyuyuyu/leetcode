class Solution {
public:
    // Space: 32 int
    int v1(const vector<int>& nums) {
        vector<int> bits(32, 0);
        for (int num : nums) {
            for (int i = 0; num && i < 32; num >>= 1, ++i) {
                bits[i] += (num & 1);
            }
        }

        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret += (bits[i] % 3) << i;
        }

        return ret;
    }

    int v2(const vector<int>& nums) {
        int bitLo = 0, bitHi = 0;
        for (int num : nums) {
            int bitLoTmp = 0, bitHiTmp = 0;
            for (int i = 0; i < 32; ++i) {
                int lo = (bitLo >> i) & 1, hi = (bitHi >> i) & 1;
                int sum = ((hi << 1) + lo + ((num >> i) & 1)) % 3;
                bitLoTmp |= (sum & 1) << i;
                bitHiTmp |= (sum >> 1) << i;
            }
            bitLo = bitLoTmp;
            bitHi = bitHiTmp;
        }

        return bitLo;
    }

    int singleNumber(vector<int>& nums) {
        //return v1(nums);
        return v2(nums);
    }
};
