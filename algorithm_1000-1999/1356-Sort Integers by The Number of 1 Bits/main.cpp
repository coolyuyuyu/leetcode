class Solution {
public:
    int popcount(uint32_t n) {
        #define MASK_01010101010101010101010101010101 (0x55555555)
        #define MASK_00110011001100110011001100110011 (0x33333333)
        #define MASK_00001111000011110000111100001111 (0x0F0F0F0F)
        #define MASK_00000000111111110000000011111111 (0x00FF00FF)
        #define MASK_00000000000000001111111111111111 (0x0000FFFF)
        #define MASK_00000000000000000000000011111111 (0x000000FF)
        n -= ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n + (n >> 4)) & MASK_00001111000011110000111100001111;
        n += (n >> 8);
        n += (n >> 16);
        return n & MASK_00000000000000000000000011111111;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [&](int num1, int num2) -> bool {
            int cnt1 = popcount(num1);
            int cnt2 = popcount(num2);
            if (cnt1 == cnt2) {
                return num1 < num2;
            }
            else {
                return cnt1 < cnt2;
            }
        };
        std::sort(arr.begin(), arr.end(), comp);

        return arr;
    }
};
