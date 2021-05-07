class Solution {
public:
    template <typename InputIterator, typename OutputIterator>
    OutputIterator PARTIAL_SUM(InputIterator first, InputIterator last, OutputIterator result) {
        typename std::iterator_traits<InputIterator>::value_type val = *first;
        *result++ = val;

        while (++first != last) {
            val = val + *first;
            *result++ = val;
        }

        return result;
    }

    vector<int> runningSum_BruteForce(vector<int>& nums) {
        auto itr = PARTIAL_SUM(nums.begin(), nums.end(), nums.begin());
        assert(itr == nums.end());
        return nums;
    }

    vector<int> runningSum_STL(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }

    vector<int> runningSum(vector<int>& nums) {
        //return runningSum_BruteForce(nums);
        return runningSum_STL(nums);
    }
};
