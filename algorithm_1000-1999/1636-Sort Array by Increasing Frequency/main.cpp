class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int base = 100;

        int freq[base * 2 + 1];
        std::fill(freq, freq + base * 2 + 1, 0);
        for (int num : nums) {
            ++freq[num + base];
        }

        std::sort(
            nums.begin(), nums.end(),
            [&](int num1, int num2) { return freq[num1 + base] < freq[num2 + base] || (freq[num1 + base] == freq[num2+ base] && num1 > num2); }
        );

        return nums;
    }
};
